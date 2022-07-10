/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:16:38 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 20:51:01 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	list_skip(t_list **list)
{
	while (_allisspace((*list)->data))
		*list = (*list)->next;
}

static void	get_height_width(t_list *list, int *height, int *width)
{
	int	len;

	while (list != NULL)
	{
		len = _strlen(list->data);
		if (len > *width)
			*width = len;
		++(*height);
		list = list->next;
	}
}

static void	deep_copy(char *dst, char *src, int len)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	while (i < len)
	{
		dst[i] = ' ';
		++i;
	}
}

void	set_map(struct s_map *map, t_list *list)
{
	int			i;

	list_skip(&list);
	get_height_width(list, &map->height, &map->width);
	map->map = _calloc(map->height, sizeof(char *));
	i = -1;
	while (++i < map->height)
	{
		map->map[i] = _calloc(map->width + 1, sizeof(char));
		deep_copy(map->map[i], list->data, map->width);
		list = list->next;
	}
}
