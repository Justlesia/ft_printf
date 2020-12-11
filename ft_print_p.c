/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/11 22:12:12 by lesia            ###   ########.fr       */
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
	char *tmp;

//	unsigned long address;
	address = (unsigned long) va_arg(va,void * );
	tmp = ft_itoa_16(address, 32);
	str = ft_strjoin("0x", tmp);
	free(tmp);


	len = ft_strlen(str);
	write(1, str, len);
	(*bytes) = (*bytes) + len;
	free(str);
	return 0;
}