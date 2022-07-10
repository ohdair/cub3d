/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:45:48 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 20:53:50 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	_isspace(int c)
{
	if (_strchr("\t\n\v\f\r ", c))
		return (1);
	return (0);
}

int	_allisspace(char *s)
{
	while (*s != '\0')
	{
		if (!_isspace(*s))
			return (0);
		++s;
	}
	return (1);
}
