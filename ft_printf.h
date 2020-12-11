//
// Created by Lesia Kiseleva on 03.12.2020.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_keys
{
	char	flags;
	int		width;
	int 		precision;
	char	length;
	char	specifier;
}				t_keys;

//t_keys ft_init(t_keys keys);
//int						ft_atoi(char *str);
//int		ft_is_in_set(const char *set, char c);


size_t	ft_strlen(const char *s);
char			*ft_itoa( int n);

t_keys * ft_keys(char **str, va_list va);
int ft_print_s(t_keys *keys, va_list va, int * bytes);
int ft_print_c(t_keys *keys, va_list va, int * bytes);
int ft_print_p(t_keys *keys, va_list va, int * bytes);
int ft_print_i(t_keys *keys, va_list va, int * bytes);
int ft_print_x(t_keys *keys, va_list va, int * bytes);
char			*ft_itoa_16(unsigned long num, int dop);
int						ft_atoi(char *str);
size_t	ft_strlen(const char *s);
int ft_is_in_set(const char *set, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_printf(const char *str, ...);
char	*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
#endif //FT_PRINTF_FT_PRINTF_H
