#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbrenton <sbrenton@42.fr>                  +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Updated: 2020/10/29 00:00:01 by sbrenton          #+#    #+#             *#
#*   Updated: 2020/11/09 00:00:01 by sbrenton         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#




NAME = libftprintf.a
HEADER = ft_printf.h
#LIBFTDIR = libft
#LIBFTNAME = libft.a

SRC = ft_printf.c ft_keys.c ft_atoi.c ft_strlen.c ft_print_s.c ft_print_c.c \
              ft_print_p.c  ft_print_i.c ft_itoa.c ft_itoa_16.c
#parser.c print_utils.c \
	print_di.c print_perc.c print_u.c print_hex.c \
	print_sc.c print_p.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#ar s = ranlib (create index)