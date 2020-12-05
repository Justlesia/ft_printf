/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:38:40 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/05 23:01:13 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int ft_parse(const char **str, va_list va, int * bytes)
{
	t_keys *keys;

	keys = ft_keys((char **)str, va);
	if (keys->specifier == '\0')
		return -1;
	if (keys->specifier == 'c' || keys->specifier == '%')
		if((ft_print_c(keys, va, bytes)) < 0)
			return -1;
	if (keys->specifier == 's')
		if((ft_print_s(keys, va, bytes)) < 0)
			return -1;
	if (keys->specifier == 'p')
		if((ft_print_p(keys, va, bytes)) < 0)
			return -1;
	if (keys->specifier == 'd' || keys->specifier == 'i' || keys->specifier == 'u')
		if((ft_print_i(keys, va, bytes)) < 0)
			return -1;
	if (keys->specifier == 'x' || keys->specifier == 'X')
		if((ft_print_i(keys, va, bytes)) < 0)
			return -1;
	free(keys);
	return 0;
}

int			ft_printf(const char *str, ...)
{
	va_list va;
	int bytes;

	bytes = 0;
	va_start(va, str);
	while (*str)
	{
		while (*str && *str != '%')
		{
			if (write(1, str++, 1) < 0)
				return (-1);
			bytes++;
		}
		if (*str == '%')
		{
			str++;
			if (ft_parse(&str, va, &bytes) < 0)
				return (-1);
		}
	}
	va_end(va);
	return (bytes);
}

int main(void)
{
	char *ch = "start";
	//char c = 'j';
	//float f = 0.75;
	//int f = 1;
//	printf("%10c,%05.2i\n",c,f);
//	ft_printf("%010c,%05.2i\n",c,f);
	printf("%1p,%5p\n",&ch,ch);
	ft_printf("%10p,%5p\n",&ch,ch);
	return (0);
}