/*
 *	mlx_utils.c
 *	by fire
 *	<loutre@courrier.dev>
 *	11/07/21 16:26:29
 *	11/07/21 16:39:15
 */

#include "fract_oil.h"

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp >> 3));
	*(unsigned int *)dst = color;
}
