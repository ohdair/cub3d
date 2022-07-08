/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:45:33 by juhur             #+#    #+#             */
/*   Updated: 2022/07/08 13:06:21 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"

static bool	check_background_data_set(t_game *g)
{
	int	i;

	i = -1;
	while (++i < MAX_DIR)
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
		if (_allisspace(cur->data))
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

static void	set_player_direction(t_game *g, char dir_char)
{
	const char		dir_chars[MAX_DIR] = {'N', 'S', 'W', 'E'};
	const t_point	dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	const t_point	plane[MAX_DIR] = {
	{0, 0.66}, {0, -0.66}, {-0.66, 0}, {0.66, 0}};
	int				i;

	i = -1;
	while (++i < MAX_DIR)
	{
		if (dir_char == dir_chars[i])
		{
			g->player.dir = dir[i];
			g->ray.plane = plane[i];
		}
	}
}

static void	set_player_position(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
		{
			if (!_strchr("NEWS", g->map.map[y][x]))
				continue ;
			g->player.pos.x = (double)x + 0.01;
			g->player.pos.y = (double)y + 0.01;
			set_player_direction(g, g->map.map[y][x]);
			g->map.map[y][x] = '0';
			return ;
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
