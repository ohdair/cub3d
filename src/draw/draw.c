/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:06:15 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 12:50:29 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

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
				mlx_pixel_put(g->mlx, g->win, x, y, g->background[CEILING].rgb);
			else
				mlx_pixel_put(g->mlx, g->win, x, y, g->background[FLOOR].rgb);
		}
	}
}

int	draw_window(t_game *g)
{
	draw_background(g);
	return (0);
}
