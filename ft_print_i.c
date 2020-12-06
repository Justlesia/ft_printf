/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/06 14:27:59 by lesia            ###   ########.fr       */
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
	int f;
	char w_padding;

	str = ft_itoa(va_arg(va,int));
	len = ft_strlen(str);

	f = 0;
	if (ft_is_in_set((" +"),((*keys).flags)) && str[0] != '-')
		f = 1;
	p = 0;
	if ((*keys).precision > 0)
		p = (*keys).precision - len;
	if ((*keys).width > 0)
	{
		if ((*keys).flags != '0' || p > 0)
			w_padding = ' ';
		else
			w_padding = '0';
		w = (*keys).width - len;
		while (w-- > (p + f))
		{
			write(1, &(w_padding), 1);
			(*bytes) ++;
		}
	}
	while (f-- > 0)
	{
		write(1, &((*keys).flags), 1);
		(*bytes) ++;
	}
	while (p-- > 0)
	{
		write(1, "0", 1);
		(*bytes) ++;
	}
	write(1, str, len);
	(*bytes) = (*bytes) + len;
	return 0;
}