# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/07/30 16:21:59 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  option_R/apply_option_r.c \
	  check_tab_doss.c \
	  option_L/apply_option_l.c \
	  fill_option.c \
	  modif_droits.c \
	  option_L/apply_option_l_fich.c \
	  option_L/apply_option_l_doss.c \
	  search_big_len.c \
	  order_tab.c \
	  No_option/apply_small_option.c \
	  No_option/apply_small_option_fich.c \
	  No_option/apply_small_option_doss.c \
	  forfreetab.c \
	  filloptiontwo.c \

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
	@gcc $(CFLAGS) -g3 -o $(NAME) -I /usr/local/include/ $(OBJ) libft/libft.a
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
