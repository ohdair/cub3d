/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:39:10 by juhur             #+#    #+#             */
/*   Updated: 2022/07/02 20:45:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_bg_color(struct s_background *background, char *color_data)
{
	const char	**ss = _split(color_data, ',');
	int			count;
	int			i;

	count = 0;
	while (ss[count] != NULL)
		++count;
	if (count != MAX_COLOR)
		quit_program(STATUS_ERROR_INVALID_MAP);
	i = RED;
	while (i < MAX_COLOR)
	{
		if (background->color[i] != -1)
			quit_program(STATUS_ERROR_INVALID_MAP);
		background->color[i] = _atoi(ss[i]);
		if (background->color[i] < 0 || background->color[i] > 255)
			quit_program(STATUS_ERROR_INVALID_MAP);
		++i;
	}
	_free_double_pointer((void ***)&ss);
}

bool	set_background(t_game *game, char *data)
{
	const char	*position[MAX_BACKGROUND_COLOR] = {"C", "F"};
	const char	**ss = _split(data, ' ');
	char		*color_data;
	int			i;
	int			j;

	color_data = NULL;
	i = -1;
	while (++i < MAX_BACKGROUND_COLOR)
	{
		if (ss[0] == NULL)
			break ;
		if (!_strcmp(ss[0], position[i]))
		{
			j = 0;
			while (ss[++j] != NULL)
				color_data = _strexpand(color_data, ss[j]);
			set_bg_color(&game->background[i], color_data);
			_free_double_pointer((void ***)&ss);
			return (true);
		}
	}
	_free_double_pointer((void ***)&ss);
	return (false);
}
