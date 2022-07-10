/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:39:10 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 15:24:54 by juhur            ###   ########.fr       */
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

static bool	check_comma(char *s)
{
	const size_t	s_len = _strlen(s);
	size_t			i;

	i = 0;
	while (i < s_len - 1)
	{
		if (!_strncmp(s, ",,", 2))
			return (false);
		++i;
		++s;
	}
	return (true);
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
		if (!_strcmp(ss[0], position[i]))
		{
			j = 0;
			while (ss[++j] != NULL)
				color_data = _strexpand(color_data, ss[j]);
			if (color_data == NULL || !check_comma(color_data))
				quit_program(STATUS_ERROR_INVALID_MAP);
			set_bg_color(&g->background[i], color_data);
			_free_double_pointer((void ***)&ss);
			return (true);
		}
	}
	_free_double_pointer((void ***)&ss);
	return (false);
}
