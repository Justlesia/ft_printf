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

int ft_print_i(t_keys *keys, va_list va, int * bytes)
{
	int len;
	char *str;
	int p;
	int w;

	str = ft_itoa(va_arg(va,int));
	len = ft_strlen(str);

	p = 0;
	if ((*keys).precision > 0)
		p = (*keys).precision - len;
	if ((*keys).width > 0)
	{
		if ((*keys).flags != '0' || p > 0)
			(*keys).flags = ' ';
		w = (*keys).width - len;
		(*bytes) = (*bytes) + w;
		while (w-- > p)
			write(1, &((*keys).flags), 1);
	}
	while (p-- > 0)
		write(1, "0", 1);

	write(1, str, len);
	//((*keys).width - len) может быть -1 на это проверки нетж
	(*bytes) = (*bytes) + len + w + ((*keys).width - len);
	return 0;
}