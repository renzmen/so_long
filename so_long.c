/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:02:55 by lrenzett          #+#    #+#             */
/*   Updated: 2023/12/01 17:48:34 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv, t_data *data)
{
	int		fd;
	int		r;
	char	*str;

	is_ber(argv);
	fd = open(argv, O_RDONLY);
	str = ft_calloc(sizeof(char), 9999);
	r = read(fd, str, 9999);
	if (r == -1)
		error("mappa non letta!");
	data->map.read = ft_split(str, 10);
	close(fd);
	free(str);
	return (data->map.read);
}

void	init_struct(t_data *data)
{
	data->map.player = 0;
	data->map.enemy = 0;
	data->map.exit = 0;
	data->map.collectible = 0;
	data->map.coll_taken = 0;
	data->image.floor = NULL;
	data->image.size = 64;
	data->image.frame = 0;
	data->image.p = 1;
	data->image.i = 1;
	data->move.p_x = 0;
	data->move.p_y = 0;
	data->move.n_x = 0;
	data->move.n_y = 0;
	data->move.ex_x = 0;
	data->move.ex_y = 0;
	data->move.counter = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error("inserisci una mappa!");
	init_struct(&data);
	read_map(argv[1], &data);
	map_size(&data);
	check(&data);
	find_path(&data);
	check_path(&data);
	init_window(&data);
	xpm_to_image(&data);
	draw_map(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop_hook(data.mlx, exit_animation, &data);
	mlx_hook(data.win, 17, 0L, close_win, &data);
	mlx_loop(data.mlx);
}
