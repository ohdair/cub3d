/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:17:30 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 17:50:24 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "event.h"
#include <stdio.h>

static void	check_extension(int ac, char *file_name)
{
	int	len;

	if (ac != 2)
		quit_program(STATUS_ERROR_ARG);
	len = _strlen(file_name);
	if (len < 5 || _strcmp(file_name + len - 4, ".cub"))
		quit_program(STATUS_ERROR_ARG);
}

int	main(int ac, char **av)
{
	t_game	game;

	check_extension(ac, av[1]);
	init(&game);
	parse(&game, av[1]);
	init_mlx(&game);
	int x = 0;
	while (x < game.map.height) {
		printf("%s\n", game.map.map[x]);
		x++;
	}
	mlx_loop_hook(game.mlx, draw_window, &game);
	mlx_hook(game.win, KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, mouse_hook, &game);
	mlx_loop(game.mlx);
}
