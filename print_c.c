/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 16:34:52 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

void ft_c_padding(t_keys *keys, int *bytes)
{
	int w;

	w = (*keys).width - 1;
	(*bytes) = (*bytes) + w;
	while (w-- > 0)
		write(1, " ", 1);
}

int ft_print_c(t_keys *keys, va_list va, int * bytes)
{
	(void)keys;
	char ch;

//	if (keys->specifier == '%')
//		ch = '%';
//	else
//		ch = (char)va_arg(va, int);

	ch = (char)va_arg(va, int);
	if ((*keys).width > 0 && (*keys).flags != '-')
		ft_c_padding(keys,bytes);
	write(1, &ch, 1);
	(*bytes)++;
	if ((*keys).width > 0 && (*keys).flags == '-')
		ft_c_padding(keys,bytes);
	return 0;
}