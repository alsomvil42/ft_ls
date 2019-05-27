# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/08/15 00:35:55 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  put_message.c \
	  check_tab_doss.c \
	  forfreetab.c \
	  ft_affich_fail.c \
	  order_tab.c \
	  search_big_len.c \
	  test_before_order.c \
	  verifstat.c \
	  No_option/apply_small_option.c \
	  No_option/apply_small_option_doss.c \
	  No_option/apply_small_option_fich.c \
	  option_L/apply_option_l.c \
	  option_L/apply_option_l_doss.c \
	  option_L/apply_option_l_fich.c \
	  option_L/create_tab_l.c \
	  option_L/fill_option.c \
	  option_L/filloptiontwo.c \
	  option_L/modif_droits.c \
	  option_R/apply_option_r.c \


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
