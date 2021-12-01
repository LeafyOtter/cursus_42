/*
 *	parsing_map.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 15:54:03
 *	31/05/31 15:52:28
 */

#include "wolf.h"

void	*i_hate_the_norm(char *line)
{
	free(line);
	return (NULL);
}

char	**recursive_ft(int fd, char **array, int *status, int size)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		exit(2);
	if (!ret && !*line)
		return (i_hate_the_norm(line));
	array = recursive_ft(fd, array, status, size + 1);
	if (!array)
	{
		*status = (size + 1);
		array = (char **)malloc(sizeof(char *) * (*status + 1));
		if (!array)
			*status = -1;
		if (!array)
			return (array);
		array[*status] = NULL;
	}
	if (status > 0)
		array[size] = line;
	else if (line)
		free(line);
	return (array);
}

/*
**	ternary ftw btw;
**
**	if (!*line && !tmp->e_flag)
**		array = recursive_ft(fd, array, tmp, size);
**	else
**		array = recursive_ft(fd, array, tmp, size + 1);
**
**	*note*: i removed it, but i will keep it here for posterity, next line can
**			replace the 4 above;
**
**	array = recursive_ft(fd, array, tmp, !!*line * (size + 1) + !*line * size);
*/

char	**parsing_map(int fd, char **map_array, t_player *player)
{
	int	status;

	status = 0;
	map_array = recursive_ft(fd, map_array, &status, 0);
	if (status < 0)
		error_cub_exit(error_malloc);
	status = 0;
	check_valid_map(map_array, player, &status);
	if (!status)
		error_map_exit(map_array, error_no_starting_pos);
	return (map_array);
}
