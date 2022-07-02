/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:57:31 by juhur             #+#    #+#             */
/*   Updated: 2022/07/02 13:12:27 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_word_num(char *s, char c)
{
	int	word_cnt;
	int	i;

	word_cnt = 0;
	i = -1;
	while (s[++i] != '\0')
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			++word_cnt;
	return (word_cnt);
}

static size_t	count_word_len(char const *s, char c)
{
	size_t	w_len;

	w_len = 0;
	while (s[w_len] != '\0' && s[w_len] != c)
		++w_len;
	return (w_len);
}

const char	**_split(char *s, char c)
{
	char	**ss;
	int		w_cnt;
	size_t	w_len;
	int		i;

	w_cnt = count_word_num(s, c);
	ss = _calloc(w_cnt + 1, sizeof(char *));
	i = -1;
	while (++i < w_cnt)
	{
		while (*s == c)
			++s;
		w_len = count_word_len(s, c);
		ss[i] = _strndup(s, w_len);
		s += w_len;
	}
	return ((const char **)ss);
}
