/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:45:31 by lrenzett          #+#    #+#             */
/*   Updated: 2023/12/01 17:50:11 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map.width * 64,
			data->map.height * 64, "so_long");
}

void	map_size(t_data *data)
{
	int	i;

	i = 0;
	data->map.width = 0;
	data->map.width = ft_strlen(data->map.read[0]);
	data->map.height = 0;
	while (data->map.read[data->map.height] != NULL)
		data->map.height++;
	while (data->map.read[i])
		if (data->map.width != (int)ft_strlen(data->map.read[i++]))
			error("la mappa non é rettangolare");
}

char	*error(char *msg)
{
	ft_printf("Error:\n%s\n", msg);
	exit(1);
}

void	xpm_to_image(t_data *data)
{
	data->image.floor = mlx_xpm_file_to_image(data->mlx,
			"./img/floor.xpm", &data->image.size, &data->image.size);
	data->image.wall = mlx_xpm_file_to_image(data->mlx,
			"./img/wall.xpm", &data->image.size, &data->image.size);
	data->image.exit = mlx_xpm_file_to_image(data->mlx,
			"./img/exit.xpm", &data->image.size, &data->image.size);
	data->image.exit2 = mlx_xpm_file_to_image(data->mlx,
			"./img/exit64-2.xpm", &data->image.size, &data->image.size);
	data->image.exit3 = mlx_xpm_file_to_image(data->mlx,
			"./img/exit64-3.xpm", &data->image.size, &data->image.size);
	data->image.exit4 = mlx_xpm_file_to_image(data->mlx,
			"./img/exit64-4.xpm", &data->image.size, &data->image.size);
	data->image.rick = mlx_xpm_file_to_image(data->mlx,
			"./img/EvilRick.xpm", &data->image.size, &data->image.size);
	data->image.rick_2 = mlx_xpm_file_to_image(data->mlx,
			"./img/EvilRick2.xpm", &data->image.size, &data->image.size);
	data->image.rick_2r = mlx_xpm_file_to_image(data->mlx,
			"./img/EvilRick2R.xpm", &data->image.size, &data->image.size);
	data->image.rick_r = mlx_xpm_file_to_image(data->mlx,
			"./img/EvilRickR.xpm", &data->image.size, &data->image.size);
	data->image.morty = mlx_xpm_file_to_image(data->mlx,
			"./img/morty.xpm", &data->image.size, &data->image.size);
	data->image.cetriolo = mlx_xpm_file_to_image(data->mlx,
			"./img/cetriolo.xpm", &data->image.size, &data->image.size);
}
