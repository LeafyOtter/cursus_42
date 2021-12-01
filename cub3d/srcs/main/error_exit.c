/*
 *	error_exit.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	31/05/31 15:30:15
 *	14/06/14 15:15:41
 */

#include "wolf.h"
/*
   void    error_exit(t_cub *cub, t_error error)
   {
   if (cub->mlx->img)
   mlx_destroy_image(cub->mlx->mlx, cub->mlx->img);
   if (cub->mlx->mlx_win)
   mlx_destroy_window(cub->mlx->mlx, cub->mlx->mlx_win);
   if (cub->mlx->mlx)
   {
   free(cub->mlx->mlx);
   }
//	free_sprite(cub->map->sprite);
error_map_exit(cub->map_array, error);
}*/

void	error_exit(t_cub *cub, t_error error)
{
	if (error == error_mlx_mlx || error == error_mlx_win)
	{
		if (cub->mlx->mlx)
			free(cub->mlx->mlx);
		error_map_exit(cub->map_array, error);
	}
	free_struct(cub);
	error_cub_exit(error);
}

void	error_map_exit(char **array, t_error error)
{
	int	i;

	i = -1;
	while (array[++i])
		if (array[i])
			free(array[i]);
	if (array[i])
		free(array[i]);
	if (array)
		free(array);
	error_cub_exit(error);
}

void	error_cub_exit(t_error error)
{
	if (!error)
		printf("Error : %s %s\n", "malloc error", \
				"i think your computer might be on fire");
	if (error == error_errno)
		printf("Error : %s\n", strerror(errno));
	if (error == error_no_argument)
		printf("Error : %s %s\n", "Missing arguments.", \
				"Expected one, 1. path_to_map");
	if (error == error_argument_nbr)
		printf("Error : %s %s\n", "Too many arguments.", \
				"Expected one, 1. path_to_map");
	if (error == error_reading_map)
		printf("Error : %s\n", "reading map");
	if (error == error_invalid_map_name)
		printf("Error : %s, %s\n", "invalid map name", \
				"it must end with the .cub extension");
	if (error == error_several_id)
		printf("Error : %s %s\n", "several identifiers.", \
				"Only one of each is expected");
	if (error == error_invalid_settings)
		printf("Error : %s format. %s\n", INV_SET, \
				"A white space is expected after the identifiers");
	if (error > error_invalid_settings)
		error_cub_exit_helper(error);
	exit(1);
}

void	error_cub_exit_helper(t_error error)
{
	if (error == error_invalid_settings_nbr)
		printf("Error : %s. %s\n", INV_SET, \
				"Invalid number of specifiers or invalid specifiers");
	if (error == error_invalid_rgb)
		printf("Error : %s\n", "Invalid rgb value");
	if (error == error_open_map)
		printf("Error : %s %s\n", "Invalid map :", "open map");
	if (error == error_several_sp)
		printf("Error : %s %s\n", "Invalid map :", \
				"severals starting positions detected");
	if (error == error_no_starting_pos)
		printf("Error : %s %s\n", "Invalid map :", \
				"no starting positions detected");
	if (error == error_img_mlx)
		printf("Error : %s %s\n", MLX_ERROR, IMG_ERROR);
	if (error == error_mlx_mlx)
		printf("Error : %s %s\n", MLX_ERROR, MLX_MLX_ERROR);
	if (error == error_mlx_win)
		printf("Error : %s %s\n", MLX_ERROR, MLX_WIN);
	if (error == error_xpm_file)
		printf("Error : %s %s\n", MLX_ERROR, MLX_XPM);
}
