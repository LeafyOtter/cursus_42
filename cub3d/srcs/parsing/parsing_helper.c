/*
 *	parsing_helper.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 15:46:43
 *	14/06/14 14:10:26
 */

#include "wolf.h"

int	open_fd(char *path_to_map)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
		error_cub_exit(error_errno);
	return (fd);
}

void	skip_wp(char **line)
{
	while (line && *line && **line)
	{
		if (ft_isspace(**line))
			(*line)++;
		else
			break ;
	}
}

int	verif_rgb(int tmp)
{
	if (tmp < 0 || tmp > 255)
		error_cub_exit(error_invalid_rgb);
	return (tmp);
}

void	init_array(char **array)
{
	array[0] = NO;
	array[1] = SO;
	array[2] = WE;
	array[3] = EA;
	array[4] = FL;
	array[5] = CE;
	array[6] = NULL;
}

void	set_status(int *status, int index)
{
	int	status_array[SPEC_SIZE];

	status_array[0] = NORTH;
	status_array[1] = SOUTH;
	status_array[2] = WEST;
	status_array[3] = EAST;
	status_array[4] = FLOOR;
	status_array[5] = CEILING;
	status_array[6] = 0;
	if (*status & status_array[index])
		error_cub_exit(error_several_id);
	*status |= status_array[index];
}
