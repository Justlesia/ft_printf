/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/05 02:47:42 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int ft_print_s(t_keys *keys, va_list va, int * bytes)
{
	int len;
	char *str;
	int w;

	str = va_arg(va,char *);
	len = ft_strlen(str);
	if ((*keys).precision > 0)
		len = (*keys).precision;
	if ((*keys).width > 0)
	{
		if ((*keys).flags != '0')
			(*keys).flags = ' ';
		w = (*keys).width - len;
		(*bytes) = (*bytes) + w;
		while (w-- > 0)
			write(1, &((*keys).flags), 1);
	}
	write(1, str, len);
	(*bytes) = (*bytes) + len;
	return 0;
}