/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:52:09 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 19:20:57 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_num(t_keys *keys, va_list va, int *bytes)
{
	char *str;
	signed long long tmp;

	tmp = ft_is_in_set("xXu", (*keys).specifier) ?
		  va_arg(va, unsigned int) : va_arg(va, int);
	if ((*keys).specifier == 'x')
		str = ft_itoa_16(tmp, 32);
	else if ((*keys).specifier == 'X')
		str = ft_itoa_16(tmp, 0);
	else if ((*keys).specifier == 'u')
		str = ft_itoa_u(tmp);
	else
		str = ft_itoa(tmp);
	ft_num_pad_and_write(str, keys, bytes);
	return (0);
}

int ft_print_p(t_keys *keys, va_list va, int *bytes)
{
	char			*str;
	char			*tmp;
	unsigned long	adress;

	adress = (unsigned long)va_arg(va, void *);
	if (keys->precision == 0)
	{
		str = ft_strjoin("", "0x");
		keys->precision = -1;
	}
	else
	{
		tmp = ft_itoa_16(adress, 32);
		str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	ft_num_pad_and_write(str, keys, bytes);
	return (0);
}
