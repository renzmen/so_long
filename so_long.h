/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:37:51 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/13 15:08:00 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_map
{
	char	**read;
	int		width;
	int		height;
	int		elements;
	int		player;
	int		enemy;
	int		exit;
	int		collectible;
	int		coll_taken;
}	t_map;

typedef struct s_move
{
	int	counter;
	int	p_x;
	int	p_y;
	int	n_x;
	int	n_y;
	int	ex_x;
	int	ex_y;
}	t_move;

typedef struct s_image
{
	int		size;
	//void	*rick;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_image;

typedef struct s_data
{
	t_move	move;
	t_map	map;
	t_image	 image;
	void	*mlx;
	void	*win;
}	t_data;

int main (int argc, char **argv);
char	**read_map(char *argv, t_data *data);
int	map_height(t_data *data);
int	map_width(t_data *data);
void	check_walls(t_data *data);
void	xpm_to_image(t_data *data);
void	draw_map(t_data *data);
void	check_map(t_data *data, int i, int j);
void	check(t_data *data);
void	init_window(t_data *data);
char	*error(char *msg);
void    init_struct(t_data *data);
void	free_map(t_data *data);
void	free_img(t_data *data);
int	close_win(t_data *data);
int	handle_key(int keycode, t_data *data);
void    get_enemy(t_data *data, int x, int y);
void	moves(t_data *data, int x, int y);
void	exchange(t_data *data, x, y);
int	expand(t_data *data, int x, int y, char c);
void	find_path(t_data *data);
//void	check_path(t_data *data);
#endif
