/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:35:37 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/23 20:33:47 by lrenzett         ###   ########.fr       */
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
		data->move.counter++;
		draw_map(data);
	}
}

void	print_move(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->move.counter);
	mlx_string_put(data->mlx, data->win, 100, 100, 0xa832a2, "MOVES:");
	mlx_string_put(data->mlx, data->win, 150, 100, 0xa832a2, moves);
	free(moves);
}




void	exchange(t_data *data, int x, int y)
{
	if (data->map.read[y][x] == '0')
		data->map.read[y][x] = '2';
	else if (data->map.read[y][x] == '2')
		data->map.read[y][x] = '0';
	if (data->map.read[y][x] == 'E')
		data->map.read[y][x] = 'U';
	else if (data->map.read[y][x] == 'U')
		data->map.read[y][x] = 'E';
	if (data->map.read[y][x] == 'C')
		data->map.read[y][x] = 'S';
	else if (data->map.read[y][x] == 'S')
		data->map.read[y][x] = 'C';
	if (data->map.read[y][x] == 'N')
		data->map.read[y][x] = 'M';
	else if (data->map.read[y][x] == 'M')
		data->map.read[y][x] = 'N';
}

int	expand(t_data *data, int x, int y, char c)
{
	if (data->map.read[y][x - 1] == c || data->map.read[y - 1][x] == c ||
	data->map.read[y][x + 1] == c || data->map.read[y + 1][x] == c)
		return (1);
	return (0);

}

void	find_path(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map.read[y])
	{
		x = 0;
		while (data->map.read[y][x])
		{
			if ((data->map.read[y][x] == '0' || data->map.read[y][x] == 'E' ||
			data->map.read[y][x] == 'N' || data->map.read[y][x] == 'C') &&
			(expand(data, x, y, 'P') || 
			expand(data, x, y, '2') || expand(data, x, y, 'U') || 
			expand(data, x, y, 'S') || expand(data, x, y, 'M')))
			{
				exchange(data, x, y);
				find_path(data);
			} 
			x++;
		}
		y++;
		print_map(data);
	}
}

void	check_path(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < (data->map.height - 1))
	{
		x = 0;
		while (x < (data->map.width - 1))
		{
			if (data->map.read[y][x] == 'C' || data->map.read[y][x] == 'E')
				error("non c'è un percoso valido nella mappa!");
			if (data->map.read[y][x] != '0')
				exchange(data, x, y);
			x++;
		}
		y++;
	}
}


void	print_map(t_data *data)
{
	int x;
	int y = 0;

	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			printf("%c", data->map.read[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
