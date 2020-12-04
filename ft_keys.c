/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:18:59 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/04 20:00:52 by lesia            ###   ########.fr       */
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

t_keys * ft_keys(char **str)
{
	t_keys *keys;
	if (!(keys = (t_keys*)malloc(sizeof(t_keys))))
		return NULL;
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
	return keys;
}