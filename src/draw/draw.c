/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:06:15 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 19:01:03 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void	draw_mini_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				pixel_put(game, j + 5, i + 5, 0x80EEEEEE);
		}
	}
	pixel_put(game, game->player.pos.y + 5, game->player.pos.x + 5, 0xEE2500);
}

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
	draw_mini_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (1);
}
