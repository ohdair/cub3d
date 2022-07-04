/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:21:15 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/04 16:26:42 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <stdio.h>

/*
** 필요 지식
** wall_x		: Mark exactly where you hit the wall in double-type coordinates, not int-type coordinates.
** tex.x		: the x-coordinates of the texture
** tex.step	: Determine how much the coordinates of the texture should be increased to the coordinates on the vertical line
** tex.pos		: The area to draw in texture
*/

static void	pre_processing(t_game *g)
{
	double	wall_x;

	if (g->ray.side == 0)
		wall_x = g->player.pos.y + g->ray.walldist * g->ray.raydir.y;
	else
		wall_x = g->player.pos.x + g->ray.walldist * g->ray.raydir.x;
	wall_x -= floor(wall_x);
	g->tex.x = (int)(wall_x * (double)(WALLSIZE));
	if (g->ray.side == 0 && g->ray.raydir.x > 0)
		g->tex.x = WALLSIZE - g->tex.x - 1;
	if (g->ray.side == 1 && g->ray.raydir.y < 0)
		g->tex.x = WALLSIZE - g->tex.x - 1;
	g->tex.step = 1.0 * WALLSIZE / g->ray.height;
	g->tex.pos = (g->ray.start - HEIGHT / 2 + g->ray.height / 2)
		* g->tex.step;
}

static int	texturing(t_game *g, unsigned int *color)
{
	if (g->ray.side == 0)
	{
		if (g->ray.raydir.x >= 0)
			*color = ((unsigned int *)(g->map.east))[64 * g->tex.y + g->tex.x];
		else
			*color = ((unsigned int *)(g->map.west))[64 * g->tex.y + g->tex.x];
	}
	else if (g->ray.side == 1)
	{
		if (g->ray.raydir.y >= 0)
			*color = ((unsigned int *)(g->map.south))[64 * g->tex.y + g->tex.x];
		else
			*color = ((unsigned int *)(g->map.north))[64 * g->tex.y + g->tex.x];
	}
	return (*color);
}

void	texture(t_game *g, int x)
{
	int				y;
	unsigned int	color;

	pre_processing(g);
	y = g->ray.start;
	while (y <= g->ray.end)
	{
		g->tex.y = (int)g->tex.pos & (WALLSIZE - 1);
		g->tex.pos += g->tex.step;
		color = texturing(g, &color);
		pixel_put(g, x, y, color);
		y++;
	}
}
