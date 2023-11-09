/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:35:37 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/09 23:56:24 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_enemy(t_data *data, int x, int y)
{
    data->move.n_x = x;
	data->move.n_y = y;
}
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