/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:38:40 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/04 19:14:45 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>


int ft_parse(const char **str, va_list va, int * bytes)
{
	t_keys *keys;


	(void)va;
	(void)bytes;
//	keys.width = '\0';
//	keys.precision = -1;
//	keys.length = '\0';
//	keys.specifier = '\0';
//	return keys;
//	char * g = va_arg(va,char *);
//	printf("%s",g);
//	printf("%d",*bytes);
	return 0;
}

int ft_keys(const char **str, va_list va, int * bytes)
{
	t_keys *keys;
	if (!(keys = (t_keys*)malloc(sizeof(t_keys))))
		return -1;
	*keys = ft_init(*keys);
	if (ft_is_in_set("-+ #0", **str) == 1)
	{
		keys->flags = **str;
		(*str)++;
	}
	if (ft_atoi((char *)(*str)) != 0 || **str == '0')
	{
		keys->width = ft_atoi((char *)(*str));
		(*str)++;
	}
	//добавить правило на *
	if (ft_is_in_set("cspdiuxX%nfge", **str) == 1)
	{
		keys->specifier = **str;
		(*str)++;
	}
	(void)va;
	(void)bytes;
//	keys.width = '\0';
//	keys.precision = -1;
//	keys.length = '\0';
//	keys.specifier = '\0';
//	return keys;
//	char * g = va_arg(va,char *);
//	printf("%s",g);
//	printf("%d",*bytes);
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
	//char *ch = "start";
	//char *ch2 = "end";
	float f = 0.75;
	//printf("%s%*f\n",ch,5,f);
	ft_printf("% 2f",f);
	return (0);
}

//[flags][width][.precision][length]specifier

