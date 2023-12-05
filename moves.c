/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:35:37 by lrenzett          #+#    #+#             */
/*   Updated: 2023/12/01 17:54:56 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_msg(data, "bye byeee");
	if (keycode == 65362 || keycode == 119)
		moves(data, data->move.p_x, data->move.p_y - 1);
	if (keycode == 65364 || keycode == 115)
		moves(data, data->move.p_x, data->move.p_y + 1);
	if (keycode == 65361 || keycode == 97)
	{
		data->image.i = 1;
		moves(data, data->move.p_x - 1, data->move.p_y);
	}
	if (keycode == 65363 || keycode == 100)
	{
		data->image.i = 0;
		moves(data, data->move.p_x + 1, data->move.p_y);
	}
	return (0);
}

void	moves(t_data *data, int x, int y)
{
	if (data->map.read[y][x] != '1')
	{
		if (x == data->move.n_x && y == data->move.n_y)
			close_msg(data, "YOU LOSE!!");
		if (x == data->move.ex_x && y == data->move.ex_y
			&& data->map.collectible == data->map.coll_taken)
			close_msg(data, "YOU WIN!!");
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
	char	*taken;
	char	*coll;

	moves = ft_itoa(data->move.counter);
	taken = ft_itoa(data->map.coll_taken);
	coll = ft_itoa(data->map.collectible);
	mlx_string_put(data->mlx, data->win, 100, 100, 0xa832a2, "MOVES:");
	mlx_string_put(data->mlx, data->win, 175, 100, 0xa832a2, moves);
	mlx_string_put(data->mlx, data->win, 100, 115, 0xa832a2, "COLLECTIBLE:");
	mlx_string_put(data->mlx, data->win, 175, 115, 0xa832a2, taken);
	mlx_string_put(data->mlx, data->win, 180, 115, 0xa832a2, "/");
	mlx_string_put(data->mlx, data->win, 185, 115, 0xa832a2, coll);
	free(moves);
	free(coll);
	free(taken);
}
