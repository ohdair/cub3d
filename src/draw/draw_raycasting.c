/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:21:19 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/04 19:03:25 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static void	calculations(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.walldist = (g->ray.sd.x - g->ray.dd.x);
	else
		g->ray.walldist = (g->ray.sd.y - g->ray.dd.y);
	g->ray.height = (int)(HEIGHT / g->ray.walldist);
	g->ray.start = (-(g->ray.height) / 2 + HEIGHT / 2);
	if (g->ray.start < 0)
		g->ray.start = 0;
	g->ray.end = (g->ray.height / 2 + HEIGHT / 2);
	if (g->ray.end >= HEIGHT)
		g->ray.end = (HEIGHT - 1);
}

static void	dda(t_game *g)
{
	while (g->ray.hit == 0)
	{
		if (g->ray.sd.x < g->ray.sd.y)
		{
			g->ray.sd.x += g->ray.dd.x;
			g->map.x += g->ray.step_x;
			g->ray.side = 0;
		}
		else
		{
			g->ray.sd.y += g->ray.dd.y;
			g->map.y += g->ray.step_y;
			g->ray.side = 1;
		}
		if (g->map.map[(int)(g->map.y)][(int)(g->map.x)] == '1')
			g->ray.hit = 1;
	}
}

static void	pre_raycasting(t_game *g, int x)
{
	g->ray.camera = (2.0 * x / (double)WIDTH - 1.0);
	g->ray.raydir.x = g->player.dir.x + g->ray.plane.x * g->ray.camera;
	g->ray.raydir.y = g->player.dir.y + g->ray.plane.y * g->ray.camera;
	g->map.x = (int)(g->player.pos.x);
	g->map.y = (int)(g->player.pos.y);
	g->ray.hit = 0;
	g->ray.dd.x = fabs(1.0 / g->ray.raydir.x);
	g->ray.dd.y = fabs(1.0 / g->ray.raydir.y);
	g->ray.step_x = 1;
	g->ray.step_y = 1;
	g->ray.sd.x = (g->map.x + 1.0 - g->player.pos.x) * g->ray.dd.x;
	g->ray.sd.y = (g->map.y + 1.0 - g->player.pos.y) * g->ray.dd.y;
	if (g->ray.raydir.x < 0)
	{
		g->ray.step_x = -1;
		g->ray.sd.x = (g->player.pos.x - g->map.x) * g->ray.dd.x;
	}
	if (g->ray.raydir.y < 0)
	{
		g->ray.step_y = -1;
		g->ray.sd.y = (g->player.pos.y - g->map.y) * g->ray.dd.y;
	}
}

void	draw_raycasting(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		pre_raycasting(game, x);
		dda(game);
		calculations(game);
		texture(game, x);
	}
}
