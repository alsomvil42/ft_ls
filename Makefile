# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/06/21 14:40:11 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS =  -Wall -Wextra -Werror
NAME = ft_ls
_GREEN = $ \033[32m
_YELLOW = $ \033[33m
_RED = $ \033[31m
_END = $ \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@gcc $(CFLAGS) -o $(NAME) -I /usr/local/include/ $(OBJ) libft/libft.a
	@echo "$(_GREEN)ft_ls compiled$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)
	@echo "libft cleaned"
	@echo "ft_ls cleaned"

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo "ft_ls fcleaned"

re: fclean all

.PHONY: libft clean fclean all re
