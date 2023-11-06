/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:37:51 by lrenzett          #+#    #+#             */
/*   Updated: 2023/10/29 17:04:20 by lrenzett         ###   ########.fr       */
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
}	t_map;

typedef struct s_moves
{
	int	counter;
	int	i;
	int	j;
	int	x;
	int	y;
	int	patrol;
}	t_moves;

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
	t_moves	moves;
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


#endif
