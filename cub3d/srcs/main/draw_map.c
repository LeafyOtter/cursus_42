/*
 *	draw_map.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 19:19:15
 *	14/06/14 00:04:14
 */

#include "wolf.h"

void	draw_square(t_cub *cub, t_square square, int color_wall)
{
	int	i;
	int	j;

	i = -1;
	while (++i < square.size)
	{
		j = -1;
		while (++j < square.size)
		{
			my_pixel_put(cub->mlx, square.x + j, square.y + i, color_wall);
		}
	}
}

void	draw_player(t_cub *cub, t_player player, int color_player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	my_pixel_put(cub->mlx, (int)(player.x * SIZE + j + SIZE), \
			(int)(player.y * SIZE + i + SIZE), color_player);
	my_pixel_put(cub->mlx, (int)(player.x * SIZE + j + SIZE - 1), \
			(int)(player.y * SIZE + i + SIZE), color_player);
	my_pixel_put(cub->mlx, (int)(player.x * SIZE + j + SIZE + 1), \
			(int)(player.y * SIZE + i + SIZE), color_player);
	my_pixel_put(cub->mlx, (int)(player.x * SIZE + j + SIZE), \
			(int)(player.y * SIZE + i + SIZE - 1), color_player);
	my_pixel_put(cub->mlx, (int)(player.x * SIZE + j + SIZE), \
			(int)(player.y * SIZE + i + SIZE + 1), color_player);
}

void	draw_map(t_cub *cub, int color_empty, int color_player)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map_array[++i])
	{
		j = -1;
		while (cub->map_array[i][++j])
		{
			if (is_notwall(cub->map_array[i][j]))
				draw_square(cub, (t_square){j * SIZE + SIZE, \
						i * SIZE + SIZE, SIZE}, color_empty);
		}
		j--;
	}
	draw_player(cub, *cub->player, color_player);
}

/*
void	draw_player(t_cub *cub, t_player player, int color_player)
{
	int	offset;

	offset = FOG * 2;
	(void)player;
	my_pixel_put(cub->mlx, (int)offset * SIZE + SIZE, \
			(int)offset * SIZE + SIZE, color_player);
	my_pixel_put(cub->mlx, (int)offset * SIZE + SIZE - 1, \
			(int)offset * SIZE + SIZE, color_player);
	my_pixel_put(cub->mlx, (int)offset * SIZE + SIZE + 1, \
			(int)offset * SIZE + SIZE, color_player);
	my_pixel_put(cub->mlx, (int)offset * SIZE + SIZE, \
			(int)offset * SIZE + SIZE - 1, color_player);
	my_pixel_put(cub->mlx, (int)offset * SIZE + SIZE, \
			(int)offset * SIZE + SIZE + 1, color_player);
}

void	draw_map(t_cub *cub, int color_empty, int color_player)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = cub->player->y - FOG;
	i = ((i > 0) * i) + (i < 0) * -1;
	a = FOG - 1;
	while (i < (cub->player->y + FOG) && cub->map_array[++i] && ++a)
	{
		j = cub->player->x - FOG;
		j = ((j > 0) * j) + (j < 0) * -1;
		b = FOG - 1;
		while (j < (cub->player->x + FOG) && cub->map_array[i][++j] && ++b)
		{
			if (is_notwall(cub->map_array[i][j]))
				draw_square(cub, (t_square){b * SIZE + SIZE, \
						a * SIZE + SIZE, SIZE}, color_empty);
			else
				draw_square(cub, (t_square){b * SIZE + SIZE, \
						a * SIZE + SIZE, SIZE}, 0x004242ff);
		}
		while (b < (FOG * 3))
				draw_square(cub, (t_square){b++ * SIZE + SIZE, \
						a * SIZE + SIZE, SIZE}, 0x004242ff);
	}
	draw_player(cub, *cub->player, color_player);
} */
