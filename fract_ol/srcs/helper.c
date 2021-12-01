/*
 *	helper.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	15/06/15 16:12:48
 *	17/07/21 16:49:30
 */

#include "fract_oil.h"

void	error_display_list(t_fract *fract, t_error error, char *name)
{
	int		i;

	i = -1;
	name += 2;
	if (error == error_missing_operand)
		printf("%s: missing operand\n", name);
	if (error == error_invalid_operand)
		printf("%s: invalid operand\n", name);
	printf("List of available fractale set:\n");
	while (++i < NB_SET)
		printf("\t- %s\n", fract->array[i]);
	exit(1);
}

void	error_mlx(t_fract *fract, t_error error)
{
	if (error == error_mlx_init)
		printf("Minilibleaks error : Couldn't connect to X server\n%s", \
				"Make sure X server is started\n");
	if (error == error_mlx_init)
		printf("Minilibleaks error : Couldn't create a window\n");
	if (error == error_mlx_init)
		free(fract->mlx->mlx);
	(void)fract;
	exit(1);
}

void	put_set_array(char **array)
{
	array[0] = JULIA;
	array[1] = MANDELBROT;
	array[2] = BURNG_SHIP;
}

int	set_fract(t_fract *fract)
{
	if (fract->set & JULIA_M)
		draw_jl(fract, fract->mlx);
	if (fract->set & MANDEL_M)
		iterate_on_px(fract, fract->mlx);
	if (fract->set & BSHIP_M)
		draw_bs(fract);
	return (1);
}

char	*set_wn(t_fract *fract)
{
	int		i;
	char	*name_array[NB_SET];

	name_array[0] = JA_WN;
	name_array[1] = MB_WN;
	name_array[2] = BS_WN;
	i = 0;
	while (!(fract->set & ft_pow(2, i)))
		i++;
	return (name_array[i]);
}
