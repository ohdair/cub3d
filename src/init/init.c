/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:39:18 by juhur             #+#    #+#             */
/*   Updated: 2022/07/01 14:47:00 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"

void	init(t_game *game, const char *file_name)
{
	t_list	*map_raw_data;

	if (!read_raw_data(&map_raw_data, file_name))
		quit_program(STATUS_ERROR_FILE_OPEN);
	if (!parse_data(game, map_raw_data))
		quit_program(STATUS_ERROR_INVALID_MAP);
}
