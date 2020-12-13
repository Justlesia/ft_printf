/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 22:31:01 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_s_padding(t_keys *keys, int bytes, int len)
{
	int w;

	if ((*keys).flags != '0')
		(*keys).flags = ' ';
	w = (*keys).width - len;
	while (w-- > 0)
	{
		write(1, &((*keys).flags), 1);
		bytes++;
	}
	return (bytes++);
}

static char		*ft_leak(char *tmp, int *leak)
{
	char	*str;

	str = ft_strjoin("", tmp);
	(*leak)++;
	return (str);
}

int				ft_print_s(t_keys *keys, va_list va, int *bytes)
{
	int		len;
	char	*str;
	int		leak;

	leak = 0;
	if (keys->specifier == '%')
		str = ft_leak("%", &leak);
	else if (!(str = va_arg(va, char *)))
		str = ft_leak("(null)", &leak);
	len = ft_strlen(str);
	if (len > 0 || str[0] == '\0')
	{
		if ((*keys).precision >= 0 && (*keys).precision < len)
			len = (*keys).precision;
		if ((*keys).width > 0 && (*keys).flags != '-')
			*bytes = ft_s_padding(keys, *bytes, len);
		write(1, str, len);
		*bytes += len;
		if ((*keys).width > 0 && (*keys).flags == '-')
			*bytes = ft_s_padding(keys, *bytes, len);
	}
	if (leak == 1)
		free(str);
	return (0);
}
