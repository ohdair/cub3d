/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:16:21 by juhur             #+#    #+#             */
/*   Updated: 2022/07/01 15:44:02 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_data(t_game *game, t_list *map_raw_data)
{
	t_list	*cur;

	(void)game;
	cur = map_raw_data;
	while (cur != NULL)
		cur = cur->next;
	return (true);
}