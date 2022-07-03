#include "cub3d.h"

/*
** 필요 데이터
player	: 1. position (X, Y) 2. direction (X, Y)
camera	: cameraX, x-coordinate in camera space
		(left of screen = -1, center of screen = 0, right of screen = 1)
plane	: the 2d raycaster version of camera plane (X, Y)
		(the player's camera plane)
hit		: check if rays collides with the wall
sideDist	: The distance of the rays from the starting point to the point where it meets the first x(y)-axis (X, Y)
deltaDist	: This is the travel distance of the ray when it's increased by 1 on the first x(y)-axis. (X, Y)
* perWallDist		:  Calculate distance projected on camera direction
rayDirection	: X, Y (rayDirX(Y) = directionX(Y) + planeX(Y) * cameraX)
DDA algorithm	: Depending on the direction of the rays, the information is stored in stepX, stepY as +1 or -1
*/
void	pre_raycasting(t_game *game, int x)
{
	game->ray.cam = (2.0 * x / (double)WIDTH - 1.0);
	game->ray.raydir.x = game->plr.dir.x + game->ray.plane.x * game->ray.cam;
}

void	draw_raycasting(t_game *game)
{
	int	x;
	x = -1;
	while (++x < WIDTH)
	{
		pre_raycasting(game, x);
	}
}