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

int ft_print_c(t_keys *keys, va_list va, int * bytes)
{
	(void)keys;
	char ch;
	int w;

	ch = (char)va_arg(va, int);
	if ((*keys).width > 0)
	{
		w = (*keys).width - 1;
		(*bytes) = (*bytes) + w;
		while (w-- > 0)
			write(1, " ", 1);
	}
	write(1, &ch, 1);
	(*bytes)++;
	return 0;
}