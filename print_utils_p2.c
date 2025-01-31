/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_toa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:12:11 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 19:18:04 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_res(int minus, int i, const char *temp)
{
	char		*res;
	int			j;

	if (!(res = (char *)malloc(sizeof(char) * (i + minus + 1))))
		return (NULL);
	j = 0;
	if (minus == 1)
	{
		res[j] = '-';
		j++;
	}
	while (j < (i + minus))
	{
		res[j] = temp[i - j - 1 + minus];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	long int	num;
	char		temp[20];
	int			i;
	int			minus;

	minus = 0;
	i = 0;
	num = (long int)n;
	if (num < 0)
	{
		num = num * -1;
		minus = 1;
	}
	while (num > 10)
	{
		temp[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	temp[i] = (num % 10) + '0';
	i++;
	if (num == 10)
		temp[i++] = '1';
	temp[i] = '\0';
	return (ft_res(minus, i, temp));
}

char			*ft_itoa_u(long int num)
{
	char		temp[20];
	int			i;
	int			minus;

	minus = 0;
	i = 0;
	while (num > 10)
	{
		temp[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	temp[i] = (num % 10) + '0';
	i++;
	if (num == 10)
		temp[i++] = '1';
	temp[i] = '\0';
	return (ft_res(minus, i, temp));
}

char			*ft_itoa_16(unsigned long num, int dop)
{
	char		temp[200];
	int			i;
	int			tmp;
	int			minus;

	minus = 0;
	i = 0;
	while (num > 16)
	{
		tmp = (num % 16);
		if (tmp > 9)
			tmp = tmp + 7 + dop;
		temp[i] = tmp + '0';
		num = num / 16;
		i++;
	}
	tmp = (num % 16);
	if (tmp > 9)
		tmp = tmp + 7 + dop;
	temp[i] = tmp + '0';
	i++;
	if (num == 16)
		temp[i++] = '1';
	temp[i] = '\0';
	return (ft_res(minus, i, temp));
}

size_t			ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}
