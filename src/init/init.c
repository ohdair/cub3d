/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:39:18 by juhur             #+#    #+#             */
/*   Updated: 2022/07/02 18:48:08 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"
#include "mlx.h"

static void	init_mlx_struct(t_game *game)
{
	game->mlx = mlx_init();
	game->win = NULL;
}

static void	init_game_struct(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAX_IMAGE)
	{
		game->wall[i].img = NULL;
		game->wall[i].path = NULL;
		game->wall[i].h = -1;
		game->wall[i].w = -1;
	}
	i = -1;
	while (++i < MAX_BACKGROUND_COLOR)
	{
		j = -1;
		while (++j < MAX_COLOR)
			game->background[i].color[j] = -1;
	}
}

static void	init_map_struct(struct s_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
}

void	init(t_game *game)
{
	init_mlx_struct(game);
	init_game_struct(game);
	init_map_struct(&game->map);
}
