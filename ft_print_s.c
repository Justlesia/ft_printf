/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/06 17:13:25 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>


void ft_s_padding(t_keys *keys, int *bytes, int len)
{
	int w;

	if ((*keys).flags != '0')
		(*keys).flags = ' ';
	w = (*keys).width - len;
	(*bytes) = (*bytes) + w;
	while (w-- > 0)
		write(1, &((*keys).flags), 1);
}


char	*ft_strdup(const char *s)
{
	size_t		l;
	size_t		n;
	char		*res;

	l = ft_strlen(s);
	if (!(res = (char *)malloc(l + 1)))
		return (NULL);
	n = 0;
	while (n < l)
	{
		res[n] = s[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}

int ft_print_s(t_keys *keys, va_list va, int *bytes)
{
	int len;
	char *str;
	char leak;

	leak = 0;
	if (!(str = va_arg(va, char *)))
	{
		str = ft_strdup(("(null)"));
		leak = 1;
	}
	len = ft_strlen(str);
	if (len > 0)
	{
		if ((*keys).precision >= 0 && (*keys).precision < len)
			len = (*keys).precision;
		if ((*keys).width > 0 && (*keys).flags != '-')
			ft_s_padding(keys, bytes, len);
		write(1, str, len);
		(*bytes) = (*bytes) + len;
		if ((*keys).width > 0 && (*keys).flags == '-')
			ft_s_padding(keys, bytes, len);
	}
	if (leak == 1)
		free(str);
	return 0;
}