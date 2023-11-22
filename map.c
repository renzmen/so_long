/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:35:18 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/13 16:00:03 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv, t_data *data)
{
	int		fd;
	int		r;
	char	*str;

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

void	check_walls(t_data *data)
{
	int	i;
	
	i = 0;
	while (i <= data->map.width - 1)
	{
		if (data->map.read[0][i] != '1' || data->map.read[data->map.height - 1][i] != '1')
			error("mappa non valida!");
		i++;
	}
	i = 0;
	while (i < data->map.height)
	{
			if (data->map.read[i][0] != '1' || data->map.read[i][data->map.width - 1] != '1')
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
    int		y;
	int		x;

	check_walls(data);
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
	find_path(data);
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
			if (data->map.read[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->image.wall,
					x * data->image.size, y * data->image.size);
			if (data->map.read[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
					x * data->image.size, y * data->image.size);
			if (data->map.read[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
					x * data->image.size, y * data->image.size);
			if (data->map.read[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
					x * data->image.size, y * data->image.size);
			x++;
		}
		y++;
	}
}
