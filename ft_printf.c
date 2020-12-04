/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:38:40 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/04 17:45:49 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

static int		ft_is_in_set(const char *set, char c)
{
	int n;

	n = 0;
	while (set[n] != '\0')
	{
		if (set[n] == c)
			return (1);
		n++;
	}
	return (0);
}

int ft_keys(const char **str, va_list va, int * bytes)
{
	t_keys *keys;

	if (!(keys = (t_keys*)malloc(sizeof(t_keys))))
		return -1;
	*keys = ft_init(*keys);
	if (ft_is_in_set("-+ #0", **str) == 1)
	{
		keys->specifier = **str;
		str++;
	}
	if (ft_is_in_set("cspdiuxX%nfge", **str) == 1)
	{
		keys->specifier = **str;
		(*str)++;
	}


	char * g = va_arg(va,char *);
	printf("%s",g);
	printf("%d",*bytes);
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
			if (ft_keys(&str, va, &bytes) < 0)
				return (-1);
			str++;
		}
	}
	va_end(va);
	return (bytes);
}

int main(void)
{
	char *ch = "start";
	float f = 0.75;
	printf("%s% 8.05f\n",ch,f);
	ft_printf("g\\g\tg%s%s",ch,ch);
	return (0);
}

//[flags][width][.precision][length]specifier

