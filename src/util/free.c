/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:24:57 by juhur             #+#    #+#             */
/*   Updated: 2022/07/02 12:28:20 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	_free(void **target)
{
	if (target == NULL || *target == NULL)
		return ;
	free(*target);
	*target = NULL;
}

void	_free_double_pointer(void ***target)
{
	int	i;

	if (target == NULL || *target == NULL)
		return ;
	i = -1;
	while ((*target)[++i] != NULL)
		_free((void **)&(*target)[i]);
	_free((void **)&(*target));
}
