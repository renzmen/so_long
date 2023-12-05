/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:24:29 by lrenzett          #+#    #+#             */
/*   Updated: 2023/11/28 12:51:44 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_msg(t_data *data, char *msg)
{
	ft_printf("\n%s\n\n", msg);
	close_win(data);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_img(data);
	mlx_destroy_display(data->mlx);
	free_map(data);
	free(data->mlx);
	exit(0);
}

void	free_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image.rick);
	mlx_destroy_image(data->mlx, data->image.rick_2);
	mlx_destroy_image(data->mlx, data->image.rick_r);
	mlx_destroy_image(data->mlx, data->image.rick_2r);
	mlx_destroy_image(data->mlx, data->image.floor);
	mlx_destroy_image(data->mlx, data->image.wall);
	mlx_destroy_image(data->mlx, data->image.exit);
	mlx_destroy_image(data->mlx, data->image.exit2);
	mlx_destroy_image(data->mlx, data->image.exit3);
	mlx_destroy_image(data->mlx, data->image.exit4);
	mlx_destroy_image(data->mlx, data->image.cetriolo);
	mlx_destroy_image(data->mlx, data->image.morty);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.read[i])
		free(data->map.read[i++]);
	free(data->map.read);
}
