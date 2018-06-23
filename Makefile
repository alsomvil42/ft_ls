# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/05/31 11:34:45 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_insertstr.c \
	  ft_strcmp_ls.c \
	  ft_ls.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
NAME = ft_ls

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	#gcc $(FLAGS) -I /usr/local/include *.c libft/*.a -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
	gcc $(FLAGS) -I /usr/local/include *.c libft/*.a -L /usr/local/lib -lX11 -lXext -lm 

%.o: %.c
	gcc $(FLAGS) -c -I include -I libft -I minilibx $^ -o $@

clean :
	make clean -C libft
	rm -rf *.o 

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
