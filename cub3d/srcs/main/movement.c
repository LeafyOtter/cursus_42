/*
 *	movement.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	21/05/21 12:10:51
 *	16/06/16 12:42:56
 */

#include "wolf.h"

void	movement_vector(double a, t_player *player, double dist)
{
	player->x += cos(a) * dist;
	player->y += sin(a) * dist;
}

/*
 *	int	hook_key_press(int keycode, t_cub *cub)
 *	{
 *		if (keycode == XK_Escape)
 *			mlx_loop_end(cub->mlx->mlx);
 *		if (keycode == XK_w || keycode == XK_Up)
 *			cub->player->key_status |= MV_UP_MASK;
 *		if (keycode == XK_s || keycode == XK_Down)
 *			cub->player->key_status |= MV_DOWN_MASK;
 *		if (keycode == XK_a || keycode == XK_Left)
 *			cub->player->key_status |= MV_LEFT_MASK;
 *		if (keycode == XK_d || keycode == XK_Right)
 *			cub->player->key_status |= MV_RIGHT_MASK;
 *		if (keycode == XK_3)
 *			cub->player->key_status |= LK_RIGHT_MASK;
 *		if (keycode == XK_1)
 *			cub->player->key_status |= LK_LEFT_MASK;
 *		return (0);
 *	}
 *
 *	int	hook_key_release(int keycode, t_cub *cub)
 *	{
 *		if (keycode == XK_w || keycode == XK_Up)
 *			cub->player->key_status &= ~MV_UP_MASK;
 *		if (keycode == XK_s || keycode == XK_Down)
 *			cub->player->key_status &= ~MV_DOWN_MASK;
 *		if (keycode == XK_a || keycode == XK_Left)
 *			cub->player->key_status &= ~MV_LEFT_MASK;
 *		if (keycode == XK_d || keycode == XK_Right)
 *			cub->player->key_status &= ~MV_RIGHT_MASK;
 *		if (keycode == XK_3)
 *			cub->player->key_status &= ~LK_RIGHT_MASK;
 *		if (keycode == XK_1)
 *			cub->player->key_status &= ~LK_LEFT_MASK;
 *		return (0);
 *	}
 */

int	hook_key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_ESCAPE)
		mlx_loop_end(cub->mlx->mlx);
	if (keycode == UP)
		cub->player->key_status |= MV_UP_MASK;
	if (keycode == DOWN)
		cub->player->key_status |= MV_DOWN_MASK;
	if (keycode == LEFT)
		cub->player->key_status |= MV_LEFT_MASK;
	if (keycode == RIGHT)
		cub->player->key_status |= MV_RIGHT_MASK;
	if (keycode == LLEFT)
		cub->player->key_status |= LK_LEFT_MASK;
	if (keycode == LRIGHT)
		cub->player->key_status |= LK_RIGHT_MASK;
	return (0);
}

int	hook_key_release(int keycode, t_cub *cub)
{
	if (keycode == UP)
		cub->player->key_status &= ~MV_UP_MASK;
	if (keycode == DOWN)
		cub->player->key_status &= ~MV_DOWN_MASK;
	if (keycode == LEFT)
		cub->player->key_status &= ~MV_LEFT_MASK;
	if (keycode == RIGHT)
		cub->player->key_status &= ~MV_RIGHT_MASK;
	if (keycode == LLEFT)
		cub->player->key_status &= ~LK_LEFT_MASK;
	if (keycode == LRIGHT)
		cub->player->key_status &= ~LK_RIGHT_MASK;
	return (0);
}

int	check_wall(char **map_array, t_player *player, double step, double dir)
{
	int	x;
	int	y;

	x = (int)(player->x + (cos(player->a + dir) * step));
	y = (int)(player->y + (sin(player->a + dir) * step));
	return (is_notwall(map_array[y][x]));
}

void	movement(t_player *player, char **map_array)
{
	if (player->key_status & MV_UP_MASK \
			&& check_wall(map_array, player, MVSTEP * 1.25, 0))
		movement_vector(player->a, player, MVSTEP);
	if (player->key_status & MV_DOWN_MASK \
			&& check_wall(map_array, player, MVSTEP * 1.25, M_PI))
		movement_vector(player->a + M_PI, player, MVSTEP);
	if (player->key_status & MV_LEFT_MASK \
			&& check_wall(map_array, player, MVSTEP * 1.25, 3 * M_PI_2))
		movement_vector(player->a + 3 * M_PI_2, player, MVSTEP);
	if (player->key_status & MV_RIGHT_MASK \
			&& check_wall(map_array, player, MVSTEP * 1.25, M_PI_2))
		movement_vector(player->a + M_PI_2, player, MVSTEP);
	if (player->key_status & LK_RIGHT_MASK)
		player->a += LKSTEP;
	if (player->key_status & LK_LEFT_MASK)
		player->a -= LKSTEP;
}
