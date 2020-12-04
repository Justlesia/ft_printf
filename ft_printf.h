//
// Created by Lesia Kiseleva on 03.12.2020.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_keys
{
	char	flags;
	int		width;
	float 		precision;
	char	length;
	char	specifier;
}				t_keys;

t_keys ft_init(t_keys keys);
int						ft_atoi(char *str);
int		ft_is_in_set(const char *set, char c);

#endif //FT_PRINTF_FT_PRINTF_H
