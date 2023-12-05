# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 18:48:01 by lrenzett          #+#    #+#              #
#    Updated: 2023/11/27 14:31:30 by lrenzett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES = -I /usr/local/include -I./includes/ -I./libft/includes/
LINKER = -L /usr/local/lib
SRCS_DIR = ./srcs/
SRCS = so_long.c map.c utils.c moves.c free.c path_finder.c animation.c
FLAGS = -Wall -Werror -Wextra -g
LIBFT = ./libft/libft.a
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
OBJS = ${SRCS:%.c=%.o}
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	cd mlx_linux && make
	cd libft && make
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_LINUX) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -fr $(OBJS)
	cd libft && make fclean
	cd mlx_linux && make clean

fclean: clean
	rm -fr so_long
	
re: fclean all