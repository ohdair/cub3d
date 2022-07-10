/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:36:40 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 17:34:19 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_list	*create_list(void *data)
{
	t_list	*new;

	new = _calloc(sizeof(t_list), 1);
	new->data = data;
	return (new);
}

t_list	*get_last_list(t_list *list)
{
	t_list	*last;

	if (list == NULL)
		return (NULL);
	last = list;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	add_list_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	last = get_last_list(*list);
	last->next = new;
}

void	remove_all_list(t_list **list)
{
	t_list	*cur;
	t_list	*next;

	if (list == NULL)
		return ;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		_free((void **)&cur->data);
		_free((void **)&cur);
		cur = next;
	}
	*list = NULL;
}
