/*
 *	main.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	15/06/15 16:12:48
 *	21/07/21 14:21:18
 */

#include "fract_oil.h"

int	hook_kp(int keycode, t_fract *fract)
{
	if (keycode == XK_i)
		printf("%f\n", fract->zoom_lvl);
	if (keycode == XK_Escape)
		mlx_loop_end(fract->mlx->mlx);
	return (0);
}

void	draw_bs(t_fract *fract)
{
	(void)fract;
}

int	scroll(int keycode, int x, int y, t_fract *fract)
{
	fract->center = (t_coord){x - (WIDTH), y - (HEIGHT)};
	if (keycode == Button4)
		fract->zoom_lvl /= ZOOM_PWR;
	if (keycode == Button5 && fract->zoom_lvl < 0.01)
		fract->zoom_lvl *= ZOOM_PWR;
//	printf("%f\n", fract->zoom_lvl);
	return (0);
}

void	init_mlx(t_fract *fract)
{
	fract->mlx->mlx = mlx_init();
	if (!fract->mlx->mlx)
		error_mlx(fract, error_mlx_init);
	fract->mlx->mlx_win = mlx_new_window(fract->mlx->mlx, WIDTH, HEIGHT, \
			set_wn(fract));
	if (!fract->mlx->mlx_win)
		error_mlx(fract, error_mlx_win);
	fract->mlx->img = NULL;
	mlx_hook(fract->mlx->mlx_win, KeyPress, KeyPressMask, hook_kp, fract);
	mlx_hook(fract->mlx->mlx_win, ButtonPress, Button5, scroll, fract);
	mlx_hook(fract->mlx->mlx_win, ClientMessage, \
			StructureNotifyMask, mlx_loop_end, fract->mlx->mlx);
	mlx_loop_hook(fract->mlx->mlx, set_fract, fract);
	mlx_loop(fract->mlx->mlx);
}

int	main(int ac, char **av)
{
	t_fract	fract;
	t_mlx	mlx;

	put_set_array(fract.array);
	if (ac < 2)
		error_display_list(&fract, error_missing_operand, av[0]);
	fract.set = parsing_arguments(&fract, ac, av);
	fract.mlx = &mlx;
	fract.zoom_lvl = 0.005f;
	fract.center = (t_coord){0, 0};
	init_mlx(&fract);
	if (mlx.img)
		mlx_destroy_image(mlx.mlx, mlx.img);
	if (mlx.mlx_win)
		mlx_destroy_window(mlx.mlx, mlx.mlx_win);
	if (mlx.mlx)
		free(mlx.mlx);
}
