# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:59:38 by mhuszar           #+#    #+#              #
#    Updated: 2023/09/12 15:59:41 by mhuszar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#hi, this is my second makefile, i hope it works
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCE = ft_printf.c print_c.c print_i.c print_p.c print_s.c print_u.c print_x.c
OBJECTS = $(SOURCE:.c=.o)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
