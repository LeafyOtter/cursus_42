/*
 *	hook_cub.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	26/05/26 15:53:20
 *	16/06/16 12:42:19
 */

#include "wolf.h"

/*
 *      hauteur = (dist_ecran x hauteur_mur) / dist        <----------------|
 *      var z = distance * Math.cos(angle);
 *      var wallHeight = this.height * height / z;
 *
 *		color[0] = get_color_texture(cub->map, player, v_wall, tmp / rc.sizeWall);
 *		color[1] = apply_shader(color[0], dbl[0]);
 *		color[0] = (color[0] < color[1]) * (color[0] - color[1]) + color[1];
 */

void	draw_wall(
		t_cub *cub,
		t_vector v_wall,
		t_player player,
		int y_column)
{
	t_rc	rc;
	int		x;
	int		z;
	int		mid_width;
	int		tmp;

	tmp = 0;
	mid_width = cub->cached->mid_width;
	rc.distorted_dist = hypot(player.x - v_wall.x, player.y - v_wall.y);
	rc.dist = rc.distorted_dist * cos(player.a - player.a_r);
	rc.size_wall = (2 / rc.dist) * cub->cached->dist_pp;
	z = (int)rc.size_wall / 2;
	if ((int)rc.size_wall > HEIGHT)
		tmp = ((int)rc.size_wall - HEIGHT) / 2;
	if ((int)rc.size_wall > HEIGHT)
		z = cub->cached->mid_height;
	x = 0;
	while (x < (cub->cached->mid_height - z))
		my_pixel_put(cub->mlx, mid_width + y_column, x++, cub->map->ceiling);
	while (x < (cub->cached->mid_height + z))
		my_pixel_put(cub->mlx, mid_width + y_column, x++, \
				apply_shader(get_color_texture(cub->map, player, v_wall, \
				(double)tmp++ / rc.size_wall), rc.dist));
	while (x < HEIGHT)
		my_pixel_put(cub->mlx, mid_width + y_column, x++, cub->map->floor);
}

void	calculate_vector(
		t_player *v_player,
		t_vector *v_orient,
		t_vector *v_wall)
{
	v_orient->x = cos(v_player->a_r);
	v_orient->y = sin(v_player->a_r);
	v_wall->x = v_player->x + v_orient->x * SHARPNESS;
	v_wall->y = v_player->y + v_orient->y * SHARPNESS;
	v_player->a_r = fmod(v_player->a_r, 2 * M_PI);
	if (v_player->a_r < 0)
		v_player->a_r = 2 * M_PI + v_player->a_r;
}

void	calculate_orientation(
		t_cub *cub,
		t_player player,
		int nbrayon)
{
	t_vector	v_orient;
	t_vector	v_wall;

	calculate_vector(&player, &v_orient, &v_wall);
	while (1)
	{
		v_wall.x += v_orient.x * SHARPNESS;
		if (!is_notwall(cub->map_array[(int)v_wall.y][(int)v_wall.x]))
		{
			player.face = east;
			if (player.a_r > M_PI_2 && player.a_r < (3 * M_PI_2))
				player.face = west;
			break ;
		}
		v_wall.y += v_orient.y * SHARPNESS;
		if (!is_notwall(cub->map_array[(int)v_wall.y][(int)v_wall.x]))
		{
			player.face = north;
			if (player.a_r > 0 && player.a_r < M_PI)
				player.face = south;
			break ;
		}
	}
	draw_wall(cub, v_wall, player, nbrayon);
}

void	init_img(t_cub *cub)
{
	if (cub->mlx->img)
		mlx_destroy_image(cub->mlx->mlx, cub->mlx->img);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx, WIDTH, HEIGHT);
	if (!cub->mlx->img)
		error_exit(cub, error_img_mlx);
	cub->mlx->addr = mlx_get_data_addr(cub->mlx->img, \
			&cub->mlx->bits_per_pixel, \
			&cub->mlx->line_length, \
			&cub->mlx->endian);
	mlx_mouse_get_pos(cub->mlx->mlx, cub->mlx->mlx_win, \
			&cub->mouse_coord->x_cf, &cub->mouse_coord->y_cf);
	if (MOUSE && (cub->mouse_coord->x_cf - cub->mouse_coord->x_pf) > 1)
		cub->player->a += (LKSTEP * 2.1);
	if (MOUSE && (cub->mouse_coord->x_cf - cub->mouse_coord->x_pf) < -1)
		cub->player->a -= (LKSTEP * 2.1);
	cub->mouse_coord->x_pf = cub->mouse_coord->x_cf;
	movement(cub->player, cub->map_array);
}

int	my_loop_hook(t_cub *cub)
{
	int			i;

	init_img(cub);
	i = cub->cached->ray_start;
	while (++i < cub->cached->mid_width)
	{
		calculate_orientation(cub, (t_player){cub->player->x, cub->player->y, \
				cub->player->a, cub->player->a + (double)(cub->cached->step * \
				(double)i), cub->player->key_status, cub->player->face, \
				cub->player->fov}, i);
	}
	if (MAP)
		draw_map(cub, 0x0028a1ed, 0x0000FFEE);
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->mlx_win, \
			cub->mlx->img, 0, 0);
	return (0);
}

//	on line 133 : 
//	draw_map(cub, 0x0028a1ed, 0x0000FFEE);
