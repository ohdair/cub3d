/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:06:16 by juhur             #+#    #+#             */
/*   Updated: 2022/07/03 16:50:54 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

#include <stdio.h>
static void	pixel_put(t_game *game, int x, int y, enum e_background_color type)
{
	int	i;

	i = (x * game->mlx.bpp / 8) + (y * game->mlx.line_l);
	game->mlx.addr[i] = (char)game->background[type].color[BLUE];
	game->mlx.addr[i + 1] = (char)game->background[type].color[GREEN];
	game->mlx.addr[i + 2] = (char)game->background[type].color[RED];
}

static void	draw_cf(t_game *game)
{
	int	y;
	int	x;

	(void)game;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++y < WIDTH)
		{
			if (y < HEIGHT / 2)
				pixel_put(game, x, y, CEILING);
			else
				pixel_put(game, x, y, FLOOR);
		}
	}
}

int	draw_window(t_game *game)
{
	draw_cf(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	return (0);
}
