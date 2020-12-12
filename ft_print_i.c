/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/12 20:46:58 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

void ft_putchar_b(char ch, int *bytes)
{
	write(1, &ch, 1);
	(*bytes)++;
}

void ft_i_padding(t_keys *keys, int *bytes, int *len, char first)
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
		w_padding = (*keys).flags != '0' || (*keys).precision > 0 ? ' ' : '0';
		w = w + (*keys).width - *len;
	}

	if (first == '-' && (*keys).flags != '-' && (*keys).precision == -1 && w_padding == '0')
	{
		ft_putchar_b('-', bytes);
		(*len)--;
	}
	while (w-- > (p + f) && w >= 0 && w_padding != 0  )
		ft_putchar_b(w_padding, bytes);
	while (f-- > 0)
		ft_putchar_b(((*keys).flags), bytes);
	if (first == '-' && ((*keys).precision != -1 || w_padding != '0'))
	{
		ft_putchar_b('-', bytes);
		(*len)--;
	}
	while (p-- > 0)
		ft_putchar_b('0', bytes);
}



void ft_i_padding_rev(t_keys *keys, int *bytes, char *str, int *len)
{
	int p;
	int w;
	char w_padding;
	int n;

	n = 0;
	if (str[0] == '-')
	{
		ft_putchar_b('-',bytes);
		n++;
	}
	w = 0;
	p = 0;

	if ((*keys).precision > 0)
		p = (*keys).precision - *(len);
	if ((*keys).precision == 0)
		w = 1;
	if ((*keys).width > 0)
	{
		w_padding = (*keys).flags != '0' || (*keys).precision > 0 ? ' ' : '0';
		w = w + (*keys).width - *len;
	}
	while ((p-- + n) > 0 && (*keys).precision >= 0)
		ft_putchar_b('0', bytes);
	if ((*keys).precision != 0 || str[0] != '0')
	{
		write(1, &(str[n]), (*len - n));
		(*bytes) = (*bytes) + (*len - n);
	}
	while (w-- > ((*keys).precision - *(len) + n) && w >= 0)
		ft_putchar_b(w_padding,bytes);
}

int ft_print_i(t_keys *keys, va_list va, int *bytes)
{
	char *str;
	int len;
	int n;

	char *tmp2;
	signed long long tmp;

	if ((*keys).specifier == '%')
		tmp = 0;
	else if (keys->specifier == 'p')
	{
		tmp = (unsigned long) va_arg(va,void * );
	}
	else
		tmp = va_arg(va, long);
	if (keys->specifier == 'p')
	{
		if (keys->precision == 0)
		{
			str = ft_strdup("0x");
			keys->precision = -1;
		}
		else {
			tmp2 = ft_itoa_16(tmp, 32);
			str = ft_strjoin("0x", tmp2);
			free(tmp2);
		}
	}
	else if ( (*keys).specifier == 'x')
		str = ft_itoa_16(tmp, 32);
	else if ( (*keys).specifier == 'X')
		str = ft_itoa_16(tmp, 0);
	else if ( (*keys).specifier == '%')
		str = ft_strdup("%");
	else if ( (*keys).specifier == 'u')
		str = ft_itoa_u(tmp);
	else
		str = ft_itoa(tmp);
	len = ft_strlen(str);
	n = 0;
	if ((*keys).flags != '-')
		{
			if (str[0] == '-')
				n++;
			ft_i_padding(keys, bytes, &len, str[0]);
			if ((*keys).precision != 0 || str[0] != '0'){
				write(1, &(str[n]), len);
				(*bytes) = (*bytes) + len;
			}
		}
		if ((*keys).flags == '-')
			ft_i_padding_rev(keys, bytes, str, &len);
	free(str);
	return 0;
}