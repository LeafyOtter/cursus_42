/*
 *	main.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	31/05/31 16:09:16
 *	13/06/13 22:47:17
 */

#include "wolf.h"

void	free_struct(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->map_array[++i])
	{
		if (cub->map_array[i])
			free(cub->map_array[i]);
	}
	if (cub->map_array[i])
		free(cub->map_array[i]);
	if (cub->map_array)
		free(cub->map_array);
	if (cub->map->north.mlx.img)
		mlx_destroy_image(cub->mlx->mlx, cub->map->north.mlx.img);
	if (cub->map->south.mlx.img)
		mlx_destroy_image(cub->mlx->mlx, cub->map->south.mlx.img);
	if (cub->map->west.mlx.img)
		mlx_destroy_image(cub->mlx->mlx, cub->map->west.mlx.img);
	if (cub->map->east.mlx.img)
		mlx_destroy_image(cub->mlx->mlx, cub->map->east.mlx.img);
	if (cub->mlx->img)
		mlx_destroy_image(cub->mlx->mlx, cub->mlx->img);
	if (cub->mlx->mlx)
		free(cub->mlx->mlx);
}

void	pre_cache(t_cached *cached)
{
	cached->mid_width = WIDTH >> 1;
	cached->mid_height = HEIGHT >> 1;
	cached->ray_start = -(cached->mid_width - 1);
	cached->step = ((double)FOV / (double)WIDTH) * (M_PI / 180);
	cached->dist_pp = (double)160 / (double)tan(FOV / 2);
}

void	init_win(t_cub *cub)
{
	t_kitty	mouse_coord;

	cub->mlx->mlx = mlx_init();
	if (!cub->mlx->mlx)
		error_exit(cub, error_mlx_mlx);
	cub->mlx->mlx_win = mlx_new_window(cub->mlx->mlx, WIDTH, HEIGHT, WIN_NAME);
	if (!cub->mlx->mlx_win)
		error_map_exit(cub->map_array, error_mlx_win);
	 mlx_mouse_get_pos(cub->mlx->mlx, cub->mlx->mlx_win, \
			 &mouse_coord.x_pf, &mouse_coord.y_pf);
	cub->mouse_coord = &mouse_coord;
	load_texture(cub->map, cub->mlx);
	mlx_hook(cub->mlx->mlx_win, KeyPress, \
			KeyPressMask, hook_key_press, cub);
	mlx_hook(cub->mlx->mlx_win, KeyRelease, \
			KeyReleaseMask, hook_key_release, cub);
	mlx_hook(cub->mlx->mlx_win, ClientMessage, \
			StructureNotifyMask, mlx_loop_end, cub->mlx->mlx);
	mlx_loop_hook(cub->mlx->mlx, my_loop_hook, cub);
	mlx_loop(cub->mlx->mlx);
	mlx_destroy_window(cub->mlx->mlx, cub->mlx->mlx_win);
}

int	main(int ac, char **av)
{
	char		**map_array;
	t_map		map;
	t_mlx		mlx;
	t_player	player;
	t_cached	cached;

	map_array = NULL;
	if (ac < 2)
		error_cub_exit(error_no_argument);
	if (ac > 2)
		error_cub_exit(error_argument_nbr);
	map_array = parsing_cub(av[1], &map, map_array, &player);
	mlx.img = NULL;
	player.key_status = 0;
	player.fov = ((M_PI * FOV) / 180);
	pre_cache(&cached);
	init_win(&(t_cub){map_array, &map, &mlx, &player, &cached, NULL});
	free_struct(&(t_cub){map_array, &map, &mlx, &player, &cached, NULL});
	return (0);
}
