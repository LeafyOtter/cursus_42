/*
 *	wolf.h
 *	by leaf
 *	<loutre@courrier.dev>
 *	20/05/20 15:09:09
 *	14/06/14 15:46:49
 */

#ifndef WOLF_H
# define WOLF_H

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
//# include <X11/keysym.h>

# include "libft.h"
# include "key_mask.h"

# ifndef MOUSE
#  define MOUSE 0
# endif

# ifndef MAP
#  define MAP 0
# endif

# define NORTH 1
# define SOUTH 2
# define WEST 4
# define EAST 8
# define FLOOR 16
# define CEILING 32
# define DOOR 64

# define TMP 6
# define LEN 5
# define SHARPNESS 0.0042
# define MVSTEP 0.06
# define LKSTEP 0.02

# define FOV 70
# define WIDTH 960
# define HEIGHT 540

# define SIZE 3
# define FOG 8

# define RES "R"
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"
# define SP "S"
# define FL "F"
# define CE "C"

# ifndef SPEC_SIZE
#  define SPEC_SIZE 7
# endif

# define CUB ".cub"

# ifndef NOTWALL
#  define NOTWALL "0"
# endif

# define INV_SET "invalid settings"
# define MLX_ERROR "unexpected error from minilibleaks :"
# define IMG_ERROR "couldn't open image"
# define MLX_MLX_ERROR "failed to set up conection with X server"
# define MLX_WIN "couldn't create a window"
# define MLX_XPM "couldn't load texture. .xpm file may be unvalid"
# define WIN_NAME "owo whats this"

/*
 *	t_error: enum used to determine what error message needs to be printed
 */

typedef enum e_error
{
	error_malloc,
	error_errno,
	error_no_argument,
	error_argument_nbr,
	error_reading_map,
	error_invalid_map_name,
	error_several_id,
	error_invalid_settings,
	error_invalid_settings_nbr,
	error_invalid_rgb,
	error_open_map,
	error_several_sp,
	error_no_starting_pos,
	error_mlx_mlx,
	error_mlx_win,
	error_img_mlx,
	error_xpm_file
}	t_error;

/*
 *	t_face:	enum used to determine what orientation a wall is facing
 */

typedef enum e_face
{
	north,
	south,
	west,
	east
}	t_face;

/*
 *	t_square:	define size of square
 */

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

/*
 *	t_kitty:	stash variable of the mouse (bonus)
 */

typedef struct s_kitty
{
	int	x_pf;
	int	y_pf;
	int	x_cf;
	int	y_cf;
}	t_kitty;

/*
 *	t_cache: pre-calculate and stash some variables.
 */

typedef struct s_cached
{
	int		mid_width;
	int		mid_height;
	int		ray_start;
	double	step;
	double	dist_pp;
}	t_cached;

/*
 *	t_rc:	structure used for ray-casting related variables
 */

typedef struct s_rc
{
	double	dist;
	double	size_wall;
	double	distorted_dist;
}	t_rc;

/*
 *	t_rgb:	structure stock an rgb value
 */

typedef struct s_rgb
{
	int	red;
	int	gre;
	int	blu;
}	t_rgb;

/*
 *	t_vector:	structure representing a vector
 */

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

/*
 *	t_mlx:		structure stocking every useful mlx related variables
 */

typedef struct s_mlx
{
	void	*mlx;
	void	*img;
	char	*addr;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

/*
 *	t_sprite:	structure stocking information about a sprite
 *				path	: either file path or pointer to image for mlx
 *				length	: length of sprite;
 *				height	: height of sprite;
 */

typedef struct s_sprite
{
	void	*path;
	int		length;
	int		height;
	t_mlx	mlx;
}	t_sprite;

/*
 *	t_map	:	structure stocking every specifiers
 *				status	: bitwise is used to keep track of the specifiers;
 *				width	: resolution;
 *				height	: resolution;
 *				floor	: rgb;
 *				ceiling	: rgb;
 *				sprite	: path to sprite files;
 */

typedef struct s_map
{
	int			status;
	int			width;
	int			height;
	int			floor;
	int			ceiling;
	t_sprite	north;
	t_sprite	south;
	t_sprite	west;
	t_sprite	east;
}	t_map;

/*
 *	t_player:	structure stocking informations about the player
 *				x		: x position of the player;
 *				y		: y position of the player;
 *				a		: orientation of the player;
 *				a_r		: orientation of ray casted;
 *				key_st..: key pressed;
 *				orient..: face hit by ray;
 *				fov		: fov of player calculated in radians;
 */

typedef struct s_player
{
	double	x;
	double	y;
	double	a;
	double	a_r;
	int		key_status;
	t_face	face;
	double	fov;
}	t_player;

/*
 *  t_cub:      structure pointing to other structures
 *				map_ar..: pointer to my map;
 *				map		: pointer to structure holding map configuration;
 *				mlx		: pointer to structure holding mlx information;
 *				player	: pointer to structure holding my player position;
 */

typedef struct s_cub
{
	char		**map_array;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	t_cached	*cached;
	t_kitty		*mouse_coord;
}	t_cub;

void	check_valid_map(char **array, t_player *player, int *status);
void	error_cub_exit(t_error error);
void	error_cub_exit_helper(t_error error);
void	error_map_exit(char **array, t_error error);
void	error_exit(t_cub *cub, t_error error);
void	init_array(char **array);
int		open_fd(char *path);
char	**parsing_cub(char *path, t_map *m_info, char **m_array, t_player *p);
char	**parsing_map(int fd, char **map_array, t_player *player);
void	set_status(int *status, int index);
int		verif_rgb(int tmp);

int		hook_key_press(int keycode, t_cub *cub);
int		hook_key_release(int keycode, t_cub *cub);
void	movement(t_player *player, char **map_array);
void	free_struct(t_cub *cub);
void	my_pixel_put(t_mlx *mlx, int x, int y, int color);
int		rd_pixel_texture(t_mlx *mlx, int x, int y);
int		my_loop_hook(t_cub *cub);

void	draw_map(t_cub *cub, int color_empty, int color_player);
void	calculate_orientation(t_cub *cub, t_player player, int nbrayon);

void	load_texture(t_map *map, t_mlx *mlx);
int		apply_shader(int color, double dist);
int		get_color_texture(t_map *map, t_player plyer, t_vector v_wll, double h);

void	skip_wp(char **line);
int		is_valid(int c);
int		is_notwall(int c);
int		is_direction(int c);

#endif
