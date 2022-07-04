/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:06:15 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 19:33:12 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void	increase_map(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = HEIGHT * 0.01 * y;
	while (i < HEIGHT * 0.01 * (y + 1))
	{
		j = WIDTH * 0.01 * x;
		while (j < WIDTH * 0.01 * (x + 1))
		{
			pixel_put(game, j + 5, i + 5, color);
			j++;
		}
		i++;
	}
}

static void	draw_mini_map(t_game *game)
{
	int		i;
	int		j;
	t_point	player;

	player = game->player.pos;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				increase_map(game, j, i, 0x80EEEEEE);
		}
	}
	increase_map(game, player.y, player.x, 0xEE2500);
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
