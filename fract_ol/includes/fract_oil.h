/*
 *	fract_oil.h
 *	by leaf
 *	<loutre@courrier.dev>
 *	15/06/15 16:06:28
 *	21/07/21 15:28:06
 */

#ifndef FRACT_OIL_H
# define FRACT_OIL_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "libft.h"

# define WIDTH		960
# define HEIGHT		720

# define ZOOM_PWR	1.1
# define NB_SET		3
# define MAX_ITER	50

# define JULIA		"Julia"
# define MANDELBROT	"Mandelbrot"
# define BURNG_SHIP	"BurningShip"
# define JULIA_M	1
# define MANDEL_M	2
# define BSHIP_M	4
# define JA_WN "fract'ol : Julia set"
# define MB_WN "fract'ol : Mandelbrot set"
# define BS_WN "fract'ol : Burningship set"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

/*
 *		used for complex number
 *			rp = real part
 *			ip = imaginary part
 */

typedef struct s_cplx
{
	double	rp;
	double	ip;
}	t_cplx;

/*		enum used for error management	*/

typedef enum e_error
{
	error_missing_operand,
	error_invalid_operand,
	error_mlx_init,
	error_mlx_win
}	t_error;

/*		classic mlx variables	*/

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

/*		cached variables	*/

typedef struct s_cv
{
	int		mid_height;
	int		mid_width;
}	t_cv;

/*
 *		main structure for this program
 *			set		= indicate set used
 *			zoom_.. = control the zoom level
 *			array[] = hold all usable set
 *			cv		= cached var
 *			mlx		= mlx related var
 */

typedef struct s_fract
{
	int		set;
	double	zoom_lvl;
	t_coord	center;
	char	*array[NB_SET];
	t_cv	cv;
	t_mlx	*mlx;
} t_fract;

/*		in srcs/helper.c	*/

void	error_display_list(t_fract *fract, t_error error, char *name);
void	error_mlx(t_fract *fract, t_error error);
void	put_set_array(char **array);
int		set_fract(t_fract *fract);
char	*set_wn(t_fract *fract);

/*		in srcs/parsing.c	*/

int		parsing_arguments(t_fract *fract, int ac, char **av);

/*		in srcs/julia.c		*/

void	draw_jl(t_fract *fract, t_mlx *mlx);

/*		in srcs/mandel.c	*/

void	iterate_on_px(t_fract *fract, t_mlx *mlx);

/*		in srcs/mlx_utils.c	*/

void	my_pixel_put(t_mlx *mlx, int x, int y, int color);

/*		in srcs/math_utils.c*/

double	ft_cabs(t_cplx cplx);

/*		in srcs/main.c		*/

void	draw_bs(t_fract *fract);

#endif
