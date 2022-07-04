/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:39:18 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 12:50:42 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"
#include "mlx.h"

static void	init_mlx_struct(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
}

static void	init_game_struct(t_game *g)
{
	int	i;

	i = -1;
	while (++i < MAX_IMAGE)
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
