/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:47:46 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/11 20:38:28 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static char		*ft_res(int i, const char *temp)
{
	char		*res;
	int			j;

	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = temp[i - j - 1];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char			*ft_itoa_16(unsigned long num, int dop)
{
	char		temp[200];
	int			i;
	int tmp;

	i = 0;
	while (num > 16)
	{
		tmp = (num % 16) ;
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
	return (ft_res(i, temp));
}
