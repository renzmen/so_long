# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 23:22:12 by lrenzett          #+#    #+#              #
#    Updated: 2023/10/11 02:45:06 by lrenzett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES = -I /usr/local/include
LINKER = -L /usr/local/lib
SRCS_DIR = ./srcs
SRCS = main.c
FLAGS = -Wall -Werror -Wextra -g
LIBFT = ./libft/libft.a
MLX_MAC = -lmlx -framework OpenGL -framework AppKit
MLX_LINUX = -Lminilibx-linux -lmlx_Linux -lmlx -lXext -lX11
OBJS = ${SRCS:%.c=%.o}
GCC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	cd minilibx_linux && make
	cd libft && make
	gcc $(FLAGS) $(OBJS) $(LIBFT) $(MLX_LINUX) -o $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $<

clean:
	rm -fr $(OBJS)
	cd libft && make clean
	cd minilibx_linux && make clean

fclean: clean
	rm -fr so_long
	cd libft && make fclean
	cd minilibx_linux && make fclean

re: fclean all