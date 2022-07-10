/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:39:18 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 20:39:07 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"
#include "mlx.h"

static void	init_mlx_struct(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->img = NULL;
	g->addr = NULL;
	g->player.pos.x = 0;
	g->player.pos.y = 0;
	g->player.dir.x = 0;
	g->player.dir.y = 0;
	g->ray.plane.x = 0;
	g->ray.plane.y = 0;
}

static void	init_game_struct(t_game *g)
{
	int	i;

	i = -1;
	while (++i < MAX_DIR)
	{
		g->wall[i].img = NULL;
		g->wall[i].path = NULL;
		g->wall[i].h = -1;
		g->wall[i].w = -1;
	}
	i = -1;
	while (++i < MAX_BACKGROUND_COLOR)
		g->background[i].rgb = -1;
}

static void	init_map_struct(struct s_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
}

void	init(t_game *g)
{
	init_mlx_struct(g);
	init_game_struct(g);
	init_map_struct(&g->map);
}
