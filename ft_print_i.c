/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/06 23:17:22 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

void ft_i_padding(t_keys *keys, int *bytes, int *len, char first)
{
	int p;
	int w;
	int f;
	char w_padding;

	w = 0;
	f = 0;
	if (ft_is_in_set((" +"), ((*keys).flags)) && first != '-')
		f = 1;
	p = 0;
	if ((*keys).precision > 0)
		p = (*keys).precision - *(len);
	if ((*keys).width > 0)
	{
		if ((*keys).flags != '0' || p > 0)
			w_padding = ' ';
		else
			w_padding = '0';
		w = (*keys).width - *len;
	}
	while (w-- > (p + f))
	{
		write(1, &(w_padding), 1);
		(*bytes)++;
	}
	while (f-- > 0)
	{
		write(1, &((*keys).flags), 1);
		(*bytes)++;
	}
	if (first == '-' && (*keys).flags != '-')
	{
		write(1, "-", 1);
		(*len)--;
	}
	while (p-- > 0)
	{
		write(1, "0", 1);
		(*bytes)++;
	}
}


int ft_print_i(t_keys *keys, va_list va, int *bytes)
{
	int tmp;
	char *str;
	int len;
	int n;

	tmp = va_arg(va, int);
	str = ft_itoa(tmp);
	len = ft_strlen(str);


	n = 0;
	if ((*keys).flags != '-')
	{
		if (str[0] == '-')
			n++;
		ft_i_padding(keys, bytes, &len, str[0]);
	}

	if ((*keys).precision == 0 && tmp == 0)
		write(1, " ", 1);
	else
	{
		write(1, &(str[n]), len);
		(*bytes) = (*bytes) + len;
		free(str);
	}

	if ((*keys).flags == '-')
		ft_i_padding(keys, bytes, &len, str[0]);

	return 0;
}