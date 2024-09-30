# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 21:50:18 by alejhern          #+#    #+#              #
#    Updated: 2024/09/23 17:57:24 by alejhern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft/

SRCS = ft_parse_flags.c ft_printers.c ft_printf.c

OBJ = $(SRCS:.c=.o)

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = $(LIB_DIR)libft.a

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -q $(NAME) $(OBJ)

$(LIBFT):
	@make -C $(LIB_DIR)

%.o: %.c ft_printf.h ft_printf_bonus.h Makefile libft.h
	$(CC) $(CFLAGS) -I $(LIB_DIR) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	@make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                BONUS                                         #
# **************************************************************************** #

bonus: $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -q $(NAME) $(OBJ)