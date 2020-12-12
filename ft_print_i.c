/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:12:47 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/12 23:04:25 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

void ft_putchar_b(char ch, int *bytes)
{
	write(1, &ch, 1);
	(*bytes)++;
}

t_padding ft_count_padding(t_keys *keys, int *len, char first)
{
	t_padding pad;

	pad.p = 0;
	pad.w = 0;
	pad.w_padding = 0;
	if ((*keys).precision > 0)
	{
		pad.p = pad.p + (*keys).precision - *(len);
		if (first == '-' &&  (*keys).flags != '-')
			(pad.p)++;
	}
	if ((*keys).precision == 0)
		pad.w = 1;
	if ((*keys).width > 0)
	{
		pad.w_padding = (*keys).flags != '0' || (*keys).precision > 0 ? ' ' : '0';
		pad.w = pad.w + (*keys).width - *len;
	}
	return pad;
}

void ft_i_padding(t_keys *keys, int *bytes, int *len, char first)
{
	t_padding pad;
	int f;

	f = 0;
	if (ft_is_in_set((" +"), ((*keys).flags)) && first != '-')
		f = 1;
	pad = ft_count_padding(keys, len, first);
	if (first == '-' && (*keys).flags != '-' && (*keys).precision == -1 && pad.w_padding == '0')
		ft_putchar_b('-', bytes);
	while (pad.w-- > (pad.p + f) && pad.w >= 0 && pad.w_padding != 0  )
		ft_putchar_b(pad.w_padding, bytes);
	while (f-- > 0)
		ft_putchar_b(((*keys).flags), bytes);
	if (first == '-' && ((*keys).precision != -1 || pad.w_padding != '0'))
		ft_putchar_b('-', bytes);
	while (pad.p-- > 0)
		ft_putchar_b('0', bytes);
}



//void ft_i_padding_rev(t_keys *keys, int *bytes, char *str, int *len)
//{
//	int n;
//	int p;
//	int w;
//	char w_padding;
//	//t_padding pad;
//
//	p = 0;
//	w = 0;
//	w_padding = 0;
//
//	n = 0;
//	if (str[0] == '-')
//	{
//		ft_putchar_b('-',bytes);
//		n++;
//	}
////	pad = ft_count_padding(keys, len, str[0]);
//
//	if ((*keys).precision > 0)
//	{
//		p = (*keys).precision - *(len);
//	}
//	if ((*keys).precision == 0)
//		w = 1;
//	if ((*keys).width > 0)
//	{
//		if ((*keys).flags != '0' || (*keys).precision > 0)
//			w_padding = ' ';
//		else
//			w_padding = '0';
//		w = w + (*keys).width - *len;
//	}
//
//	if ((*keys).precision > 0)
//		p = (*keys).precision - *(len);
//	if ((*keys).precision == 0)
//		w = 1;
//	if ((*keys).width > 0)
//	{
//		w_padding = (*keys).flags != '0' || (*keys).precision > 0 ? ' ' : '0';
//		w = w + (*keys).width - *len;
//	}
//	while ((p-- + n) > 0 && (*keys).precision >= 0)
//		ft_putchar_b('0', bytes);
//	if ((*keys).precision != 0 || str[0] != '0')
//	{
//		write(1, &(str[n]), (*len - n));
//		(*bytes) = (*bytes) + (*len - n);
//	}
//	while (w-- > ((*keys).precision - *(len) + n) && w >= 0)
//		ft_putchar_b(w_padding,bytes);
//}


void ft_i_padding_rev(t_keys *keys, int *bytes, char *str, int *len)
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


void ft_num_pad_and_write(char *str, t_keys *keys, int *bytes)
{
	int len;
	int n;

	len = ft_strlen(str);
	n = 0;

	if ((*keys).flags != '-')
	{
		if (str[0] == '-')
			n++;
		ft_i_padding(keys, bytes, &len, str[0]);
		if ((*keys).precision != 0 || str[0] != '0')
		{
			write(1, &(str[n]), len - n);
			(*bytes) = (*bytes) + len - n ;
		}
	}
	if ((*keys).flags == '-')
		ft_i_padding_rev(keys, bytes, str, &len);
	free(str);
}

int ft_print_num(t_keys *keys, va_list va, int *bytes)
{
	char *str;
	signed long long tmp;

	tmp = ft_is_in_set("xXu",(*keys).specifier) ?
			va_arg(va, unsigned int) : va_arg(va, int);
	if ((*keys).specifier == 'x')
		str = ft_itoa_16(tmp, 32);
	else if ((*keys).specifier == 'X')
		str = ft_itoa_16(tmp, 0);
	else if ((*keys).specifier == 'u')
		str = ft_itoa_u(tmp);
	else
		str = ft_itoa(tmp);
	ft_num_pad_and_write(str, keys, bytes);
	return 0;
}


int ft_print_p_pct(t_keys *keys, va_list va, int *bytes)
{
	char *str;
	char *tmp;
	unsigned long adress;

	if (keys->specifier == 'p')
	{
		adress = (unsigned long)va_arg(va, void *);
		if (keys->precision == 0)
		{
			str = ft_strdup("0x");
			keys->precision = -1;
		}
		else
		{
			tmp = ft_itoa_16(adress, 32);
			str = ft_strjoin("0x", tmp);
			free(tmp);
		}
	}
	else
		str = ft_strdup("%");
	ft_num_pad_and_write(str, keys, bytes);
	return 0;
}
