/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:45:33 by juhur             #+#    #+#             */
/*   Updated: 2022/07/03 17:33:01 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"

static bool	check_background_data_set(t_game *game)
{
	int	i;

	i = -1;
	while (++i < MAX_IMAGE)
		if (game->wall[i].path == NULL)
			return (false);
	i = -1;
	while (++i < MAX_BACKGROUND_COLOR)
		if (game->background[i].color[RED] == -1)
			return (false);
	return (true);
}

void	parse_data(t_game *game, t_list *map_raw_data)
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
		if (check_background_data_set(game))
		{
			set_map(&game->map, cur);
			return ;
		}
		if (!set_image(game, cur->data) && !set_background(game, cur->data))
			quit_program(STATUS_ERROR_INVALID_MAP);
		cur = cur->next;
	}
}

void	parse(t_game *game, const char *file_name)
{
	t_list	*map_raw_data;

	if (!read_raw_data(&map_raw_data, file_name))
		quit_program(STATUS_ERROR_FILE_OPEN);
	parse_data(game, map_raw_data);
	check_map(game->map);
}
