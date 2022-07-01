/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:33:10 by juhur             #+#    #+#             */
/*   Updated: 2022/07/01 15:05:27 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "util.h"

/*
** read_a_line() is a function that reads a string from fd
** until it includes '\n' or reaches eof.
** If the result of the read() function is an error (-1),
** return -1, otherwise return length of read buffer.
*/
static ssize_t	read_a_line(int fd, char **backup)
{
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t	read_len;

	read_len = 0;
	while (*backup == NULL || _strchr(*backup, '\n') == NULL)
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		read_buf[read_len] = '\0';
		*backup = _strexpand(*backup, read_buf);
		if (*backup == NULL)
			break ;
	}
	return (read_len);
}

/*
** get_a_line() is a function that returns a string excluding '\n'.
*/
static char	*get_a_line(char **backup)
{
	char	*line;
	char	*trim;
	size_t	trim_len;

	trim_len = _strchr(*backup, '\n') - *backup + 1;
	line = _strndup(*backup, trim_len - 1);
	if (line == NULL)
		return (NULL);
	trim = _strndup(*backup + trim_len, _strlen(*backup) - trim_len);
	if (trim == NULL)
	{
		_free((void **)&line);
		return (NULL);
	}
	_free((void **)backup);
	*backup = trim;
	return (line);
}

/*
** get_next_line() is a function that reads a data using fd
** and returns a line exclude the '\n'. if an error has occurred
** or there is nothing more to read, return NULL.
*/
char	*get_next_line(int fd)
{
	static char	*backup;
	ssize_t		read_len;
	char		*line;

	read_len = read_a_line(fd, &backup);
	if (read_len == -1 || backup == NULL)
		return (NULL);
	if (_strchr(backup, '\n') != NULL)
		return (get_a_line(&backup));
	if (_strlen(backup) == 0)
	{
		_free((void **)&backup);
		return (NULL);
	}
	line = _strndup(backup, _strlen(backup));
	if (line == NULL)
		return (NULL);
	_free((void **)&backup);
	return (line);
}
