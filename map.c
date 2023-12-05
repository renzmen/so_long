/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:35:18 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/27 23:22:31 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->map.width - 1)
	{
		if (data->map.read[0][i] != '1' ||
		data->map.read[data->map.height - 1][i] != '1')
			error("mappa non valida!");
		i++;
	}
	i = 0;
	while (i < data->map.height)
	{
		if (data->map.read[i][0] != '1' ||
		data->map.read[i][data->map.width - 1] != '1')
			error("mappa non valida!");
		i++;
	}
}

void	check_map(t_data *data, int x, int y)
{
	if (!(data->map.read[y][x] == '0' || data->map.read[y][x] == '1'
	|| data->map.read[y][x] == 'C' || data->map.read[y][x] == 'P'
	|| data->map.read[y][x] == 'E' || data->map.read[y][x] == 'N'))
		error("mappa non valida");
	if (data->map.read[y][x] == 'N')
	{
		data->map.enemy++;
		data->move.n_x = x;
		data->move.n_y = y;
	}
	if (data->map.read[y][x] == 'P')
	{
		data->map.player++;
		data->move.p_x = x;
		data->move.p_y = y;
	}
	if (data->map.read[y][x] == 'E')
	{
		data->map.exit++;
		data->move.ex_x = x;
		data->move.ex_y = y;
	}
	if (data->map.read[y][x] == 'C')
		data->map.collectible++;
}

void	check(t_data *data)
{
	int	y;
	int	x;

	check_walls(data);
	if (data->map.height == data->map.width)
		error("la mappa non é rettangolare!");
	y = 1;
	while (y < data->map.height)
	{
		x = 1;
		while (x < data->map.width)
		{
			check_map(data, x, y);
			x++;
		}
		y++;
	}
	if (data->map.player > 1)
		error("deve esserci un solo giocatore nella mappa!");
	if (data->map.exit != 1)
		error("deve esserci una sola uscita nella mappa!");
	if (data->map.collectible <= 0)
		error("deve esserci almeno un collezionabile nella mappa!");
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.read[y][x] == 'P')
				player_animation(data, x, y);
			if (data->map.read[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->image.wall,
					x * 64, y * 64);
			if (data->map.read[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
					x * 64, y * 64);
			if (data->map.read[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
					x * 64, y * 64);
			draw_map2(data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map2(t_data *data, int x, int y)
{
	if (data->map.read[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->image.cetriolo,
			x * 64, y * 64);
	if (data->map.read[y][x] == 'N')
		mlx_put_image_to_window(data->mlx, data->win, data->image.morty,
			x * 64, y * 64);
	print_move(data);
}
