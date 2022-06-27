/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:17:30 by juhur             #+#    #+#             */
/*   Updated: 2022/06/27 18:39:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "util.h"

static bool	check_extension(int ac, char *file_name)
{
	int	len;

	if (ac != 2)
		return (false);
	len = _strlen(file_name);
	if (len < 5 || _strcmp(file_name + len - 4, ".cub"))
		return (false);
	return (true);
}

static int	quit_program(const char *s)
{
	if (s != NULL)
		write(STDOUT_FILENO, s, _strlen(s));
	return (1);
}

int	main(int ac, char **av)
{
	if (!check_extension(ac, av[1]))
		quit_program("[usage]: ./cub3D <FILE_NAME.cub>\n");
	return (0);
}
