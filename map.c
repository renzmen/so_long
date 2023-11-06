/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:35:18 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/01 00:08:57 by lrenzett         ###   ########.fr       */
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

void	check_map(t_data *data, int i, int j)
{
	if (!(data->map.read[i][j] == '0' || data->map.read[i][j] == '1'
		|| data->map.read[i][j] == 'C' || data->map.read[i][j] == 'P'
		|| data->map.read[i][j] == 'E' || data->map.read[i][j] == 'N'))
			error("mappa non valida");
    if (data->map.read[i][j] == 'N')
	{
        if (++data->map.enemy > 1)
			error("non ci puó essere piú di un nemico nella mappa!");
	}
	
	if (data->map.read[i][j] == 'P')
		data->map.player++;
	if (data->map.read[i][j] == 'E')
		data->map.exit++;
	if (data->map.read[i][j] == 'C')
		data->map.collectible++;
}


void	check(t_data *data)
{
    int		i;
	int		j;

	check_walls(data);
    i = 1;
	while (i < data->map.height)
	{
		j = 1;
		while (j < data->map.width)
		{
			check_map(data, i, j);
			j++;
		}
		i++;
	}
	if (data->map.player > 1)
		error("deve esserci un solo giocatore nella mappa!");
	if (data->map.exit != 1)
		error("deve esserci una sola uscita nella mappa!");	
	if (data->map.collectible <=0)
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
			if (data->map.read[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->image.wall,
					x * data->image.size, y * data->image.size);
			if (data->map.read[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
					x * data->image.size, y * data->image.size);
			if (data->map.read[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
					x * data->image.size, y * data->image.size);
			x++;
		}
		y++;
	}
}
