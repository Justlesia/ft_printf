/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/04 23:46:04 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int ft_print_p(t_keys *keys, va_list va, int * bytes)
{
	(void)keys;
	int len;
	char *str;
	char *point;

	str = va_arg(va,char *);
	point = (void *)str;
	len = ft_strlen(point);
	write(1, &point, len);
	(*bytes) = (*bytes) + len;
	return 0;
}