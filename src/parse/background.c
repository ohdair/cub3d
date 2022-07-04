/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:39:10 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 13:47:15 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_rgb(int red, int green, int blue)
{
	if (red < 0 || green < 0 || blue < 0)
		quit_program(STATUS_ERROR_INVALID_MAP);
	if (red > 255 || green > 255 || blue > 255)
		quit_program(STATUS_ERROR_INVALID_MAP);
}

static int	create_rgb(int red, int green, int blue)
{
	check_rgb(red, green, blue);
	return (red << 16 | green << 8 | blue);
}

static void	set_bg_color(struct s_background *background, char *color_data)
{
	const char	**ss = _split(color_data, ',');
	int			color;

	color = 0;
	while (ss[color] != NULL)
		++color;
	if (color != MAX_COLOR || background->rgb != -1)
		quit_program(STATUS_ERROR_INVALID_MAP);
	background->rgb = create_rgb(_atoi(ss[0]), _atoi(ss[1]), _atoi(ss[2]));
	_free_double_pointer((void ***)&ss);
}

bool	set_background(t_game *g, char *data)
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
			set_bg_color(&g->background[i], color_data);
			_free_double_pointer((void ***)&ss);
			return (true);
		}
	}
	_free_double_pointer((void ***)&ss);
	return (false);
}
