/*
 *	mandel.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	28/06/28 18:22:23
 *	21/07/21 14:45:33
 */

#include "fract_oil.h"

int	mandel_set(t_fract *fract, int x, int y)
{
	t_cplx	crnt;
	t_cplx	next;
	t_cplx	c;
	int		iter;

	iter = 0;
	crnt = (t_cplx){0, 0};
	c = (t_cplx){(double)x * fract->zoom_lvl, (double)y * fract->zoom_lvl};
	while (iter < MAX_ITER)
	{
		iter++;
		next.rp = crnt.rp * crnt.rp - crnt.ip * crnt.ip + c.rp;
		next.ip = 2 * crnt.rp * crnt.ip + c.ip;
		crnt = next;
		if (ft_cabs(crnt) > 4.0f)
			break ;
	}
	return (iter);
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
			iter = mandel_set(fract, j - (WIDTH >> 1) + fract->center.x, i - (HEIGHT >> 1) + fract->center.y);
			if (iter < 25)
				my_pixel_put(mlx, j, i, 0x00ffffff);
		}
	}
	my_pixel_put(mlx, WIDTH >> 1, HEIGHT >> 1, 0x00ff0000);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
