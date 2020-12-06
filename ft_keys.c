/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:18:59 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/05 02:08:01 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

static t_keys ft_init(t_keys keys)
{
	keys.flags = '\0';
	keys.width = -1;
	keys.precision = -1;
	keys.length = '\0';
	keys.specifier = '\0';
	return keys;
}

int ft_is_in_set(const char *set, char c)
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

char ft_char(char **str)
{
	char ch;
	ch = **str;
	(*str)++;
	return ch;
}

int ft_num(char **str)
{
	int num;
	char *tmp;

	while(**str == '0')
		(*str) ++;
	num = ft_atoi((char *)(*str));
	tmp = ft_itoa(num);
	(*str) = (*str) + ft_strlen(tmp);
	free(tmp);
	return num;
}

int ft_va_arg(va_list va,char **str)
{
	int num;

	num = va_arg(va, int);
	(*str)++;
	return num;
}

t_keys *ft_keys(char **str, va_list va)
{
	t_keys *keys;

	if (!(keys = (t_keys *)malloc(sizeof(t_keys))))
		return NULL;
	*keys = ft_init(*keys);
	if (ft_is_in_set("-+ #0", **str) == 1)
		keys->flags = ft_char(str);
	if (ft_atoi((char *)(*str)) != 0 || **str == '0')
		keys->width = ft_num(str);
	if (ft_is_in_set("*", **str) == 1)
		keys->width = ft_va_arg(va,str);
	if (ft_is_in_set(".", **str) == 1)
	{
		(*str)++;
		if ((ft_is_in_set("*", **str) == 1))
			keys->precision = ft_va_arg(va,str);
		else
			keys->precision = ft_num(str);
	}
	if (ft_is_in_set("cspdiuxX%nfge", **str) == 1)
		keys->specifier = ft_char(str);
	return keys;
}