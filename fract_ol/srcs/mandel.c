/*
 *	mandel.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	28/06/28 18:22:23
 *	21/07/21 15:54:17
 */

#include "fract_oil.h"

/*	hsv to rgb
 *	When 0 ≤ H < 360 (0 is less than or equal to Hue and less than 360)
 *	0 ≤ S ≤ 1 (0 is less than or equal to saturation which is less than or equal to 1)
 *	and 0 ≤ V ≤ 1 (0 is less than or equal to value and less than or equal to 1);
 *
 * C = V × S
 *
 * X = C × (1 - | (H / 60°) mod 2 - 1|)
 *
 * m = V - C
 *
 * (R, G, B) = ((R'+ m) ×255, (G'+ m) ×255, (B'+ m) ×255)
*/


int	mandel_set(t_fract *fract, int x, int y)
{
	(void)fract;
	t_cplx	pxl;
	double	zoom = 1.5;
	double moveX = -0.75, moveY = 0;
	double newRe, newIm, oldRe, oldIm;

	pxl = (t_cplx){1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX, \
		(y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY};
	newRe = newIm = oldRe = oldIm = 0;
	int i = -1;
	while (++i < 128)
	{
		oldRe = newRe;
		oldIm = newIm;

		newRe = oldRe * oldRe - oldIm * oldIm + pxl.rp;
		newIm = 2 * oldRe * oldIm + pxl.ip;
		if ((newRe * newRe + newIm * newIm) > 4)
			break ;
	}
	return (i);
}

void	iterate_on_px(t_fract *fract, t_mlx *mlx)
{
	int	i;
	int	j;
	int	iter;

	i = -1;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, \
			&mlx->line_length, &mlx->endian);
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			iter = mandel_set(fract, j, i);
			if (iter < 25)
				my_pixel_put(mlx, j, i, 0x00ffffff);
		}
	}
	my_pixel_put(mlx, WIDTH >> 1, HEIGHT >> 1, 0x00ff0000);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
