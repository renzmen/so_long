/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:35:37 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/11 00:29:05 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_win(data);
	/*if (keycode == 65362 || keycode == 119)
		player_up(game);
	if (keycode == 65364 || keycode == 115)
		player_down(game);
	if (keycode == 65361 || keycode == 97)
		player_left(game);
	if (keycode == 65363 || keycode == 100)
		player_right(game);*/
	return (0);
}
void	moves(t_data *data, unsigned int x, unsigned int y)
{
	if (data->map.read[y][x] == '1')
	{
		check_move(data, x, y);
		
	}
}

void	check_move(t_data *data, unsigned int x, unsigned int y)
{
	if (x && y == data->move.n_x && data->move.n_y)
		close_win(data);
	if (x && y == data->move.ex_x && data->move.ex_y)
		close_win(data);
	if (data.map.read[y][x] == 'C')
		data->map.coll_taken++;
	data->map.read[y][x] = 'P';
	data->map.read[data->move.p_y][data->move.p_x] = '0';
	
}
