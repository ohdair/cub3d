/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:06:15 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 18:00:53 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	pixel_put(t_game *game, int x, int y, int color)
{
	int	i;

	i = (x * game->bpp / 8) + (y * game->line_l);
	game->addr[i] = (char)(color);
	game->addr[i + 1] = (char)(color >> 8);
	game->addr[i + 2] = (char)(color >> 16);
}

static void	draw_background(t_game *g)
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
				pixel_put(g, x, y, g->background[CEILING].rgb);
			else
				pixel_put(g, x, y, g->background[FLOOR].rgb);
		}
	}
}

int	draw_window(t_game *g)
{
	draw_background(g);
	draw_raycasting(g);
	// draw_mini_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (1);
}
