/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:38:16 by lrenzett          #+#    #+#             */
/*   Updated: 2023/12/05 12:54:41 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	x;
	int	y;

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

void	is_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!(str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
			&& str[len - 4] == '.'))
		error("il file contenente la mappa avere estensione '.ber'");
}
