/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:37:51 by lrenzett          #+#    #+#             */
/*   Updated: 2023/10/14 00:00:23 by lrenzett         ###   ########.fr       */
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
	char	**mapm;
	char	*mapv;
	int		width;
	int		height;
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
	int		size_img;
	void	*current_player;
	void	*starr;
	void	*starl;
	//void	*star;
	void	*enemy;
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*exit;
	int		victory_obj;
	char	*display_moves;
	int		patrol_flag;
}	t_image;

typedef struct s_data
{
	t_moves	moves;
	t_map	map;
	t_image	 imag;
	void	*mlx;
	void	*win;
}	t_data;

int		main();
#endif
