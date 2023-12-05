/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:07:32 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/27 23:16:37 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_data *data, int x, int y)
{
	if (data->image.i == 1 && data->image.p == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.rick,
			x * 64, y * 64);
		data->image.p = 0;
	}
	else if (data->image.i == 1 && data->image.p == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.rick_2,
			x * 64, y * 64);
		data->image.p = 1;
	}
	else if (data->image.i == 0 && data->image.p == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.rick_r,
			x * 64, y * 64);
		data->image.p = 0;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.rick_2r,
			x * 64, y * 64);
		data->image.p = 1;
	}
}

int	exit_animation(t_data *data)
{
	if (data->map.collectible == data->map.coll_taken)
	{
		data->image.frame += 1;
		if (data->image.frame <= 2000)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
				data->move.ex_x * 64, data->move.ex_y * 64);
		if (data->image.frame > 2000 && data->image.frame <= 4000)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit2,
				data->move.ex_x * 64, data->move.ex_y * 64);
		if (data->image.frame > 4000 && data->image.frame <= 6000)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit3,
				data->move.ex_x * 64, data->move.ex_y * 64);
		if (data->image.frame > 6000 && data->image.frame <= 8000)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit4,
				data->move.ex_x * 64, data->move.ex_y * 64);
		if (data->image.frame > 8000)
			data->image.frame = 0;
	}
	return (0);
}
