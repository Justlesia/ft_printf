/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:04:17 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 19:04:17 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_putchar_b(char ch, int *bytes)
{
	write(1, &ch, 1);
	(*bytes)++;
}

static t_padding	ft_count_padding(t_keys *keys, int *len, char first)
{
	t_padding	pad;

	pad.p = 0;
	pad.w = 0;
	pad.w_padding = 0;
	if ((*keys).precision > 0)
	{
		pad.p = pad.p + (*keys).precision - *(len);
		if (first == '-')
			(pad.p)++;
	}
	if ((*keys).precision == 0 && first == '0')
		pad.w = 1;
	if ((*keys).width > 0)
	{
		pad.w_padding = (*keys).flags != '0' || (*keys).precision >= 0 ?
				' ' : '0';
		pad.w = pad.w + (*keys).width - *len;
	}
	return (pad);
}

static void			ft_padding(t_keys *keys, int *bytes, int *len, char first)
{
	t_padding	pad;
	int			f;

	f = 0;
	if (ft_is_in_set((" +"), ((*keys).flags)) && first != '-')
		f = 1;
	pad = ft_count_padding(keys, len, first);
	if (first == '-' && (*keys).flags != '-'
	&& (*keys).precision == -1 && pad.w_padding == '0')
		ft_putchar_b('-', bytes);
	while (pad.w-- > (pad.p + f) && pad.w >= 0 && pad.w_padding != 0)
		ft_putchar_b(pad.w_padding, bytes);
	while (f-- > 0)
		ft_putchar_b(((*keys).flags), bytes);
	if (first == '-' && ((*keys).precision != -1 || pad.w_padding != '0'))
		ft_putchar_b('-', bytes);
	while (pad.p-- > 0)
		ft_putchar_b('0', bytes);
}

static void			ft_pad_rev(t_keys *keys, int *bytes, char *str, int *len)
{
	t_padding	pad;
	int			n;

	n = 0;
	if (str[0] == '-')
	{
		ft_putchar_b('-', bytes);
		n++;
	}
	pad = ft_count_padding(keys, len, str[0]);
	if (pad.p > 0)
	{
		while ((pad.p--) > 0 && (*keys).precision >= 0)
			ft_putchar_b('0', bytes);
	}
	if ((*keys).precision != 0 || str[0] != '0')
	{
		write(1, &(str[n]), (*len - n));
		(*bytes) = (*bytes) + (*len - n);
	}
	while (pad.w-- > ((*keys).precision - *(len) + n)
	&& pad.w >= 0 && pad.w_padding != 0)
		ft_putchar_b(pad.w_padding, bytes);
}

void				ft_num_pad_and_write(char *str, t_keys *keys, int *bytes)
{
	int		len;
	int		n;

	len = ft_strlen(str);
	n = 0;
	if ((*keys).flags != '-')
	{
		if (str[0] == '-')
			n++;
		ft_padding(keys, bytes, &len, str[0]);
		if ((*keys).precision != 0 || str[0] != '0')
		{
			write(1, &(str[n]), len - n);
			(*bytes) = (*bytes) + len - n;
		}
	}
	if ((*keys).flags == '-')
		ft_pad_rev(keys, bytes, str, &len);
	free(str);
}
