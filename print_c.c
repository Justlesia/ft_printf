/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 18:38:43 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_c_padding(t_keys *keys, int *bytes)
{
	int		w;

	w = (*keys).width - 1;
	(*bytes) = (*bytes) + w;
	while (w-- > 0)
		write(1, " ", 1);
}

int				ft_print_c(t_keys *keys, va_list va, int *bytes)
{
	char	ch;

	(void)keys;
	ch = (char)va_arg(va, int);
	if ((*keys).width > 0 && (*keys).flags != '-')
		ft_c_padding(keys, bytes);
	write(1, &ch, 1);
	(*bytes)++;
	if ((*keys).width > 0 && (*keys).flags == '-')
		ft_c_padding(keys, bytes);
	return (0);
}
