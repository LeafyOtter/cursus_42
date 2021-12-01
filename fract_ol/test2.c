#include "fract_oil.h"

int	tmp(char *str)
{
	return (0);
}

int	scroll(int button, char *str)
{
	if (button == 4)
		printf("Down\n");
	else
		printf("Up\n");
	return (0);
}

int main(void)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 980, 540, "Hello world");
	mlx_hook(mlx.mlx_win, ButtonPress, Button5, scroll, NULL);
	mlx_hook(mlx.mlx_win, ClientMessage, StructureNotifyMask, exit, 0);
	mlx_loop_hook(mlx.mlx, tmp, NULL);
	mlx_loop(mlx.mlx);
}
