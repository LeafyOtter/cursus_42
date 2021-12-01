/*
 *	draw_stuff.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 19:21:28
 *	13/06/13 17:06:13
 */

#include "wolf.h"

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

int	rd_pixel_texture(t_mlx *mlx, int x, int y)
{
	int		color;
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel >> 3));
	color = *(unsigned int *)dst;
	return (color);
}
