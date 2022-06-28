/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strexpand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:30:19 by juhur             #+#    #+#             */
/*   Updated: 2022/06/28 19:37:44 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*_strexpand(char *old, const char *s)
{
	char	*new;
	size_t	old_len;
	size_t	s_len;

	if (s == NULL)
		return (old);
	s_len = _strlen(s);
	if (old == NULL)
		return (_strdup(s));
	old_len = _strlen(old);
	new = _calloc(old_len + s_len + 1, sizeof(char));
	_strlcat(new, old, old_len + 1);
	_free((void **)&old);
	_strlcat(new, s, old_len + s_len + 1);
	return (new);
}
