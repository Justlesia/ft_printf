/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 23:09:30 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 21:12:24 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_space_at(char i)
{
	if ((i >= 7 && i <= 13) || i == 32 || i == 0)
		return (1);
	else
		return (0);
}

static int			ft_prep_at(char *str)
{
	int			i;
	int			m;

	i = 0;
	m = 1;
	while (str[i] != '\0' && ft_space_at(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	return (i * m);
}

int					ft_atoi(char *str)
{
	int				i;
	long long		pr;
	long long		nb;
	int				m;

	nb = 0;
	m = 1;
	if ((i = ft_prep_at(str)) < 0)
	{
		i = i * -1;
		m = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		pr = nb;
		nb = nb * 10 + (str[i] - '0');
		i++;
		if (pr > nb && m == 1)
			return (-1);
		if (pr > nb && m == -1)
			return (0);
	}
	return (nb * m);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t		n;
	size_t		s1_len;
	size_t		s2_len;
	char		*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (char *)malloc((s1_len + s2_len))))
		return (NULL);
	n = 0;
	while (n < s1_len)
	{
		res[n] = s1[n];
		n++;
	}
	n = 0;
	while (n < s2_len)
	{
		res[n + s1_len] = s2[n];
		n++;
	}
	res[n + s1_len] = '\0';
	return (res);
}

int					ft_is_in_set(const char *set, char c)
{
	int		n;

	n = 0;
	while (set[n] != '\0')
	{
		if (set[n] == c)
			return (1);
		n++;
	}
	return (0);
}
