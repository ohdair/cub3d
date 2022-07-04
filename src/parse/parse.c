/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:45:33 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 20:25:03 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"

static bool	check_background_data_set(t_game *g)
{
	int	i;

	i = -1;
	while (++i < MAX_IMAGE)
		if (g->wall[i].path == NULL)
			return (false);
	i = -1;
	while (++i < MAX_BACKGROUND_COLOR)
		if (g->background[i].rgb == -1)
			return (false);
	return (true);
}

void	parse_data(t_game *g, t_list *map_raw_data)
{
	t_list	*cur;

	cur = map_raw_data;
	while (cur != NULL)
	{
		if (_strlen(cur->data) == 0)
		{
			cur = cur->next;
			continue ;
		}
		if (check_background_data_set(g))
		{
			set_map(&g->map, cur);
			return ;
		}
		if (!set_image(g, cur->data) && !set_background(g, cur->data))
			quit_program(STATUS_ERROR_INVALID_MAP);
		cur = cur->next;
	}
}

static void	set_player_position(t_game *g)
{
	for (int i = 0; i < g->map.height; i++) {
		for (int j = 0; j < g->map.width; j++) {
			if (_strchr("NEWS", g->map.map[i][j])) {
				g->player.pos.x = j;
				g->player.pos.y = i;
				if (g->map.map[i][j] == 'N')
				{
					g->player.dir.y = -1;
					g->ray.plane.x = 0.66;
				}
				else if (g->map.map[i][j] == 'S')
				{
					g->player.dir.y = 1;
					g->ray.plane.x = -0.66;
				}
				else if (g->map.map[i][j] == 'W')
				{
					g->player.dir.x = -1;
					g->ray.plane.y = -0.66;
				}
				else if (g->map.map[i][j] == 'E')
				{
					g->player.dir.x = 1;
					g->ray.plane.y = 0.66;
				}
			}
		}
	}
}

void	parse(t_game *g, const char *file_name)
{
	t_list	*map_raw_data;

	if (!read_raw_data(&map_raw_data, file_name))
		quit_program(STATUS_ERROR_FILE_OPEN);
	parse_data(g, map_raw_data);
	check_map(&g->map);
	set_player_position(g);
}
