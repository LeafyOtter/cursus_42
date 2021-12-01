/*
 *	parsing_valid_map.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 16:07:47
 *	31/05/31 15:51:56
 */

#include "wolf.h"

static void	check_map(char **array, int i, int j)
{
	if (!*array[i - 1] || !is_valid(array[i - 1][j]))
		error_map_exit(array, error_open_map);
	if (!array[i + 1] || !*array[i + 1] || !is_valid(array[i + 1][j]))
		error_map_exit(array, error_open_map);
	if (!array[i][j + 1] || !is_valid(array[i][j + 1]))
		error_map_exit(array, error_open_map);
	if (!j || !array[i][j - 1] || !is_valid(array[i][j - 1]))
		error_map_exit(array, error_open_map);
}

float	set_orientation(char c)
{
	if (c == 'N')
		return (3 * M_PI_2);
	if (c == 'W')
		return (M_PI);
	if (c == 'S')
		return (M_PI_2);
	return (0);
}

void	check_valid_map(char **array, t_player *player, int *status)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
		{
			if (is_direction(array[i][j]))
			{
				if (*status)
					error_map_exit(array, error_several_sp);
				*status = 1;
				player->x = (float) j;
				player->y = (float) i;
				player->a = set_orientation(array[i][j]);
			}
			if (is_notwall(array[i][j]))
				check_map(array, i, j);
		}
	}
}
