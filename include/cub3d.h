/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:25:16 by juhur             #+#    #+#             */
/*   Updated: 2022/07/01 14:46:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include "util.h"

typedef enum e_error
{
	STATUS_OK,
	STATUS_ERROR_ARG,
	STATUS_ERROR_FILE_OPEN,
	STATUS_ERROR_ALLOC,
	STATUS_ERROR_INVALID_MAP,
	STATUS_MAX
}	t_error;

typedef struct s_image
{
	void	*image;
	char	*path;
	int		height;
	int		width;
}	t_image;

typedef struct s_wall
{
	t_image	east;
	t_image	west;
	t_image	south;
	t_image	north;
}	t_wall;

typedef struct s_background
{
	int		red;
	int		green;
	int		blue;
}	t_background;

typedef struct s_game
{
	t_wall			wall;
	t_background	ceiling;
	t_background	floor;
}	t_game;

/*
** init
*/
void	init(t_game *game, const char *file_name);
bool	read_raw_data(t_list **map_raw_data, const char *file_name);
bool	parse_data(t_game *game, t_list *map_raw_data);

/*
** quit
*/
int		quit_program(t_error errno);

#endif
