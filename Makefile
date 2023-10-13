# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 18:48:01 by lrenzett          #+#    #+#              #
#    Updated: 2023/10/13 17:53:59 by lrenzett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES = -I /usr/local/include/
LINKER = -L /usr/local/lib/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC = so_long.c
FLAGS = -Wall -Werror -Wextra -g
LIBFT = ./libft/libft.a
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
OBJ = ${SRC:%.c=%.o}
GCC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	cd mlx_linux && make
	cd libft && make
	gcc $(FLAGS) $(OBJ) $(LIBFT) $(MLX_LINUX) -o $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $<

clean:
	rm -fr $(OBJ)
	cd libft && make clean
	cd mlx_linux && make clean

fclean: clean
	rm -fr so_long
	cd libft && make fclean
#	cd mlx_linux && make fclean

re: fclean all