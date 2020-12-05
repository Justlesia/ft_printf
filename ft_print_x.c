/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/05 22:59:59 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int ft_print_x(t_keys *keys, va_list va, int * bytes)
{
	unsigned long num;
	char * str;
	int len;
	int w;

	num = (int) va_arg(va,unsigned long);
	str = ft_itoa_16(num);
	len = ft_strlen(str);

	if ((*keys).width > 0)
	{
		w = (*keys).width - 1;
		(*bytes) = (*bytes) + w;
		while (w-- > 0)
			write(1, " ", 1);
	}
	write(1, str, len);
	(*bytes) = (*bytes) + len;
	return 0;
}