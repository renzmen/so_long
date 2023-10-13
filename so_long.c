/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:02:55 by lrenzett          #+#    #+#             */
/*   Updated: 2023/10/14 00:03:53 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main ()
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 21 * 64,
			11 * 64, "so_long");
    mlx_loop(data.mlx);
}















/*NAME 		= so_long
INCLUDES 	= -I./includes/ -I./libft/includes/ -I./usr/local/include/
LINKER 		= -L /usr/local/lib/
SRC_DIR 	= ./src/
0BJ_DIR		= obj
SRCS_FILES 	= so_long.c
FLAGS 		= -Wall -Werror -Wextra -g
LIBFT 		= ./libft/libft.a
MLX_MAC 	= -lmlx -framework OpenGL -framework AppKit
MLX_LINUX 	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CC 			= gcc
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:%.c=%.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC)
	@mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ_DIR)
	cd mlx_linux && make
	cd libft && make
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_LINUX) -o $(NAME)



clean:
	rm -fr $(OBJS)
	cd libft && make clean
	cd mlx_linux && make clean

fclean: clean
	rm -fr so_long

re: fclean all*/