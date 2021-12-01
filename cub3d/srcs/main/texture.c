/*
 *	texture.c
 *	by wind
 *	<loutre@courrier.dev>
 *	12/06/12 01:36:36
 *	13/06/13 17:04:08
 */

#include "wolf.h"

int	get_color_texture(t_map *map,
		t_player player,
		t_vector v_wall,
		double height)
{
	int			i;
	int			color;
	double		*wall;
	t_sprite	*sprite;

	i = 0;
	wall = &v_wall.x;
	sprite = &map->north;
	if (player.face == north || player.face == south)
		v_wall.x -= floor(v_wall.x);
	else
		v_wall.y -= floor(v_wall.y);
	while (i++ < (int)player.face)
		sprite++;
	if (player.face >= 2)
		wall++;
	*wall *= sprite->length;
	height *= (double)sprite->height;
	color = rd_pixel_texture(&sprite->mlx, (int)*wall, (int)height);
	return (color);
}

void	load_texture(t_map *map,
		t_mlx *mlx)
{
	int			i;
	t_sprite	*sprite;

	i = 0;
	sprite = &map->north;
	while (i < 4)
	{
		sprite->mlx.img = mlx_xpm_file_to_image(mlx->mlx, \
				sprite->path, \
				&sprite->length, \
				&sprite->height);
		if (sprite->path)
			free(sprite->path);
		if (!sprite->mlx.img)
			error_cub_exit(error_xpm_file);
		sprite->mlx.addr = mlx_get_data_addr(sprite->mlx.img, \
				&sprite->mlx.bits_per_pixel, \
				&sprite->mlx.line_length, \
				&sprite->mlx.endian);
		sprite++;
		i++;
	}
}
