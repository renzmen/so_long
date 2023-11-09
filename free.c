/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:24:29 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/08 14:37:46 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_img(data);
	mlx_destroy_display(data->mlx);
	ft_free_map(data);
	free(data->mlx);
	exit(0);
}

void	free_img(t_data *data)
{
	//mlx_destroy_image(data->mlx, data->image.rick);
	mlx_destroy_image(data->mlx, data->image.floor);
	//mlx_destroy_image(data->mlx, data->image.collectible);
	mlx_destroy_image(data->mlx, data->image.wall);
	mlx_destroy_image(data->mlx, data->image.exit);
	//mlx_destroy_image(data->mlx, data->exit2);
	//mlx_destroy_image(data->mlx, data->exit3);
	//mlx_destroy_image(data->mlx, data->zero);
	//mlx_destroy_image(data->mlx, data->one);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.read[i])
	{
		free(data->map.read[i]);
		i++;
	}
	free(data->map.read);
}