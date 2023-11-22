/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:35:37 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/13 15:42:58 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_win(data);
	if (keycode == 65362 || keycode == 119)
		moves(data, data->move.p_x, data->move.p_y - 1);
	if (keycode == 65364 || keycode == 115)
		moves(data, data->move.p_x, data->move.p_y + 1);
	if (keycode == 65361 || keycode == 97)
		moves(data, data->move.p_x - 1, data->move.p_y);
	if (keycode == 65363 || keycode == 100)
		moves(data, data->move.p_x + 1, data->move.p_y);
	return (0);
}

void	moves(t_data *data, int x, int y)
{
	if (data->map.read[y][x] != '1')
	{
		if (x == data->move.n_x &&  y == data->move.n_y)
			close_win(data);
		if (x == data->move.ex_x && y == data->move.ex_y &&
		data->map.collectible == data->map.coll_taken)
			close_win(data);
		if (data->map.read[y][x] == 'C')
			data->map.coll_taken++;
		data->map.read[y][x] = 'P';
		data->map.read[data->move.p_y][data->move.p_x] = '0';
		data->move.p_y = y;
		data->move.p_x = x;
		draw_map(data);
	}
}



void	exchange(t_data *data, x, y)
{
	if (game->map[a][b] == '0')
		game->map[a][b] = '2';
	if (game->map[a][b] == '2')
		game->map[a][b] = '0';
	if (game->map[a][b] == 'E')
		game->map[a][b] = 'U';
	if (game->map[a][b] == 'U')
		game->map[a][b] = 'E';
	if (game->map[a][b] == 'C')
		game->map[a][b] = 'S';
	if (game->map[a][b] == 'S')
		game->map[a][b] = 'C';
	if (game->map[a][b] == 'N')
		game->map[a][b] = 'M';
	if (game->map[a][b] == 'M')
		game->map[a][b] = 'N';
}

int	expand(t_data *data, int x, int y, char c)
{
	if (game->map.read[y][x - 1] == c || game->map.read[y - 1][x] == c ||
	game->map.read[y][x + 1] == c || game->map.read[y + 1][x] == c)
		return (1);
	return (0);

}

void	find_path(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.read[y][x] == '0' || data->map.read[y][x] == 'E' ||
			data->map.read[y][x] == 'N' || data->map.read[y][x] == 'C' &&
			(expand(data, i, j, 'P') || 
			expand(data, i, j, '2') || expand(data, i, j, 'U') || 
			expand(data, i, j, 'S') || expand(data, i, j, 'M')))
			{
				exchange(data, x, y);
				control_path(data);
			}
			if (game->map.read[y][x] == 'C' || game->map.read[y][x] == 'E')
				error("non c'è un percoso valido nella mappa!");
			exchange(data, x, y);
			x++;
		}
		y++;
	}
	//check_path(data);
}

/*void	check_path(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (game->map.read[y][x] == 'C' || game->map.read[y][x] == 'E')
				error("non c'è un percoso valido nella mappa!");
			exchange(data, x, y);
			x++;
		}
		y++;
	}
}*/