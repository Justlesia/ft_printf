/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:38:40 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/04 23:41:57 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int ft_parse(const char **str, va_list va, int * bytes)
{
	t_keys *keys;

	keys = ft_keys((char **)str);
	(void)va;
	(void)bytes;
	if (keys->specifier == 'c' || keys->specifier == '%')
		if((ft_print_c(keys, va, bytes)) < 0)
			return -1;
	if (keys->specifier == 's')
		if((ft_print_s(keys, va, bytes)) < 0)
			return -1;
	if (keys->specifier == 'p')
		if((ft_print_p(keys, va, bytes)) < 0)
			return -1;


	//pdiuxX
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
	//printf("%s%*f\n",ch,5,f);
	ft_printf("%s,%p",ch,&ch);
	return (0);
}