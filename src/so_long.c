/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:02:55 by lrenzett          #+#    #+#             */
/*   Updated: 2023/10/13 17:52:01 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main ()
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 21 * 64,
			11 * 64, "so_long");
    mlx_loop(data.mlx);
}