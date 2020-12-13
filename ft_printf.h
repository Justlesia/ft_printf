/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:03:58 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/13 17:16:54 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <ntsid.h>
# include <stdlib.h>

typedef struct	s_keys
{
	char		flags;
	int			width;
	int			precision;
	char		specifier;
}				t_keys;

typedef struct	s_padding
{
	int			w;
	int 		p;
	char		w_padding;
}				t_padding;

size_t			ft_strlen(const char *s);
int				ft_atoi(char *str);
char			*ft_itoa(int n);
char			*ft_itoa_u(long int n);
char			*ft_itoa_16(unsigned long num, int dop);
t_keys 			*ft_keys(char **str, va_list va);
int				ft_print_s(t_keys *keys, va_list va, int *bytes);
int				ft_print_c(t_keys *keys, va_list va, int *bytes);
int 			ft_print_p(t_keys *keys, va_list va, int *bytes);
int 			ft_print_num(t_keys *keys, va_list va, int *bytes);
size_t			ft_strlen(const char *s);
int 			ft_is_in_set(const char *set, char c);
int				ft_printf(const char *str, ...);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
