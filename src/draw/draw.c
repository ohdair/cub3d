/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:06:15 by juhur             #+#    #+#             */
/*   Updated: 2022/07/03 20:47:15 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_pixel_put(game->mlx, game->win, x, y, game->background[CEILING].rgb);
			else
				mlx_pixel_put(game->mlx, game->win, x, y, game->background[FLOOR].rgb);
		}
	}
}

int	draw_window(t_game *game)
{
	draw_background(game);
	return (0);
}
