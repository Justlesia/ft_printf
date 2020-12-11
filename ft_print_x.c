/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/11 20:12:12 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

void ft_x_padding(t_keys *keys, int *bytes, int *len, char first)
{
	int p;
	int w;
	int f;
	char w_padding;

	w = 0;
	f = 0;
	p = 0;
	if (ft_is_in_set((" +"), ((*keys).flags)) && first != '-')
		f = 1;
	if ((*keys).precision > 0)
	{
		p = p + (*keys).precision - *(len);
		if (first == '-')
			p++;
	}
	if ((*keys).precision == 0)
		w = 1;
	if ((*keys).width > 0)
	{
		if ((*keys).flags != '0' || (*keys).precision > 0)
			w_padding = ' ';
		else
			w_padding = '0';
		w = w + (*keys).width - *len;
	}
	if (first == '-' && (*keys).flags != '-' && (*keys).precision == -1 && w_padding == '0')
	{
		write(1, "-", 1);
		(*len)--;
		(*bytes)++;
	}
	while (w-- > (p + f) && w >= 0 && w_padding != 0  )
	{
		write(1, &(w_padding), 1);
		(*bytes)++;
	}
	while (f-- > 0)
	{
		write(1, &((*keys).flags), 1);
		(*bytes)++;
	}
	if (first == '-' && (*keys).flags != '-' && ((*keys).precision != -1 || w_padding != '0'))
	{
		write(1, "-", 1);
		(*len)--;
		(*bytes)++;
	}
	while (p-- > 0)
	{
		write(1, "0", 1);
		(*bytes)++;
	}
}

void ft_x_padding_rev(t_keys *keys, int *bytes, char *str, int *len)
{
	int p;
	int w;
	char w_padding;
	int f;
	int n;

	f = 0;
	n = 0;
	if (str[0] == '-')
	{
		write(1, "-", 1);
//		(*len--;
		(*bytes)++;
		n++;
		//f++;
	}
	w = 0;
	p = 0;
	if ((*keys).precision > 0)
	{
		p = (*keys).precision - *(len);
	}
	if ((*keys).precision == 0)
		w = 1;
	if ((*keys).width > 0)
	{
		if ((*keys).flags != '0' || (*keys).precision > 0)
			w_padding = ' ';
		else
			w_padding = '0';
		w = w + (*keys).width - *len;
	}
//	while (w-- > (p + f) && w >= 0)
//	{
//		write(1, &(w_padding), 1);
//		(*bytes)++;
//	}
//	while (f-- > 0)
//	{
//		write(1, &((*keys).flags), 1);
//		(*bytes)++;
//	}
	while ((p-- + n) > 0 && (*keys).precision >= 0)
	{
		write(1, "0", 1);
		//if (p > 0)
		(*bytes)++;
	}
	if ((*keys).precision != 0 || str[0] != '0')
	{
		write(1, &(str[n]), (*len - n));
		(*bytes) = (*bytes) + (*len - n);
		//free(str);
	}
	while (w-- > ((*keys).precision - *(len) + n) && w >= 0)
	{
		write(1, &(w_padding), 1);
		(*bytes)++;
	}
}

int ft_print_x(t_keys *keys, va_list va, int *bytes)
{
	long tmp;
	char *str;
	int len;
	int n;

	tmp = va_arg(va, long);
	str = ft_itoa_16(tmp);
	len = ft_strlen(str);

	n = 0;
//	if ((*keys).precision != 0 || tmp != 0)

	if ((*keys).flags != '-')
	{
		if (str[0] == '-')
			n++;
		ft_x_padding(keys, bytes, &len, str[0]);
		if ((*keys).precision != 0 || str[0] != '0')
		{
			write(1, &(str[n]), len);
			(*bytes) = (*bytes) + len;
		}
	}
	if ((*keys).flags == '-')
	{
		ft_x_padding_rev(keys, bytes, str, &len);
	}

	free(str);
	return 0;
}

//int ft_print_x(t_keys *keys, va_list va, int * bytes)
//{
//	unsigned long num;
//	char * str;
//	int len;
//	int w;
//
//	num = (int) va_arg(va,unsigned long);
//	str = ft_itoa_16(num);
//	len = ft_strlen(str);
//
//	if ((*keys).width > 0)
//	{
//		w = (*keys).width - 1;
//		(*bytes) = (*bytes) + w;
//		while (w-- > 0)
//			write(1, " ", 1);
//	}
//	write(1, str, len);
//	(*bytes) = (*bytes) + len;
//	free(str);
//	return 0;
//}