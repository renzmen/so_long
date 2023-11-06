/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:45:31 by lrenzett          #+#    #+#             */
/*   Updated: 2023/10/31 23:41:27 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map.width * data->image.size, data->map.height * data->image.size, "so_long");
}
int	map_width(t_data *data)
{
	data->map.width = 0;
	data->map.width = ft_strlen(data->map.read[0]);
	return (data->map.width);
}
int	map_height(t_data *data)
{
	data->map.height = 0;
	while (data->map.read[data->map.height] != NULL)
		data->map.height++;
	return (data->map.height);
}
char	*error(char *msg)
{
	ft_printf("Error:\n%s\n", msg);
	exit(1);
}
void	xpm_to_image(t_data *data)
{
	data->image.floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &data->image.size, &data->image.size);
	data->image.wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &data->image.size, &data->image.size);
	data->image.exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &data->image.size, &data->image.size);
	
}
void    init_struct(t_data *data)
{
    data->map.player = 0;
    data->map.enemy = 0;
    data->map.exit = 0;
    data->map.collectible = 0;
    
    data->image.floor = NULL;
	data->image.size = 64;

}