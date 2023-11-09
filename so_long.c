/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:02:55 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/10 00:32:15 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char **argv)
{
    t_data  data;

	if (argc != 2)
		error("inserisci una mappa!");
	init_struct(&data);
	read_map(argv[1], &data);
	map_width(&data);
	map_height(&data);
	printf("3\n");
	check(&data);
	printf("4\n");
	init_window(&data);
	printf("5\n");	
	xpm_to_image(&data);
	draw_map(&data);

	mlx_key_hook(data.win, handle_key, &data);
	//mlx_loop_hook(data.mlx, put_exit_animation, &data);
	mlx_hook(data.win, 17, 0L, close_win, &data);
	
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