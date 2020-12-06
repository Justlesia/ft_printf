/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/05 21:20:16 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int ft_print_p(t_keys *keys, va_list va, int * bytes)
{
	(void)keys;
	int len;
	unsigned long address;
	char *str;

	address = (int) va_arg(va,void * );
	str = ft_itoa_16(address);
	len = ft_strlen(str);
	write(1, str, len);
	(*bytes) = (*bytes) + len;
	free(str);
	return 0;
}