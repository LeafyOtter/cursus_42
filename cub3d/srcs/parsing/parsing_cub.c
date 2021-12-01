/*
 *	parsing_cub.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 15:44:12
 *	14/06/14 15:21:04
 */

#include "wolf.h"

void	parsing_path(char *line, t_map *map_info, int index)
{
	char	*line_trimmed;

	line += 2 * sizeof(char);
	if (!ft_isspace(*line))
		error_cub_exit(error_invalid_settings);
	line_trimmed = ft_strtrim(line, " \t");
	if (!line_trimmed)
		error_cub_exit(error_malloc);
	if (!index)
		map_info->north.path = line_trimmed;
	if (index == 1)
		map_info->south.path = line_trimmed;
	if (index == 2)
		map_info->west.path = line_trimmed;
	if (index == 3)
		map_info->east.path = line_trimmed;
}

void	parsing_rgb(int *a, char *line)
{
	int		i;
	int		j;
	char	*temp;
	char	*line_trimmed;

	i = 3;
	*a = 0;
	line++;
	if (!ft_isspace(*line))
		error_cub_exit(error_invalid_settings);
	line_trimmed = ft_strtrim(line, " \t");
	if (!line_trimmed)
		error_cub_exit(error_malloc);
	temp = line_trimmed;
	while (--i >= 0)
	{
		j = ft_atoi_skip(&line_trimmed);
		*a |= verif_rgb(j) << i * 8;
		skip_wp(&line_trimmed);
		line_trimmed++;
	}
	if (temp)
		free(temp);
}

/*
 *	@name	:	check if file name given as argument finish with .cub,
 *				calls error_cub_exit function if file name is incorrect;
 *	@return	:	void;
 *	@param1	:	the path to .cub file given as an argument;
 */

void	parsing_name(char *path_to_map)
{
	char	*tmp;

	tmp = ft_strnstr(path_to_map, CUB, ft_strlen(path_to_map));
	if (!tmp)
		error_cub_exit(error_invalid_map_name);
	if (*(tmp + ft_strlen(CUB)))
		error_cub_exit(error_invalid_map_name);
}

void	parsing_line(int i, char *line, t_map *map_info, char **array)
{
	char	*tmp;

	i = -1;
	tmp = line;
	while (line && ft_isspace(*line))
		line++;
	if (!*line)
	{
		free(tmp);
		return ;
	}
	tmp = NULL;
	while (!tmp && array[++i])
		tmp = ft_strnstr(line, array[i], ft_strlen(line));
	if (!tmp && map_info->status != (ft_pow(2, SPEC_SIZE - 1) - 1))
		error_cub_exit(error_invalid_settings_nbr);
	if (i >= 0 && i <= 3)
		parsing_path(tmp, map_info, i);
	if (i == 4)
		parsing_rgb(&map_info->floor, tmp);
	if (i == 5)
		parsing_rgb(&map_info->ceiling, tmp);
	free(line);
	set_status(&map_info->status, i);
}

/*
 *	@name	:	main function for parsing, initialize a bunch of variables,
 *				and call other parsing function;
 *	@return	:	return @param2 once the map is stocked inside;
 *	@param0	:	path to .cub file given as an argument;
 *	@param1	:	structure stocking every specifiers given
 *				resolution = t_map.width, t_map.height
 *				color of floor/ceiling = t_map.floor, t_map.ceiling
 *				structure stocking path to sprites;
 *	@param2	:   2-dimensional array stocking the map;
 *	@param3	:   position of player;
 */

char	**parsing_cub(char *path_to_map, t_map *map_info, char **map_array,
t_player *player)
{
	int		fd;
	int		ret;
	char	*line;
	char	*define_array[SPEC_SIZE];

	ret = 1;
	map_info->status = 0;
	parsing_name(path_to_map);
	init_array(define_array);
	fd = open_fd(path_to_map);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			error_cub_exit(error_reading_map);
		parsing_line(ret, line, map_info, define_array);
		if (map_info->status == (ft_pow(2, SPEC_SIZE - 1) - 1))
			break ;
	}
	if (ret == 0)
		error_cub_exit(error_invalid_settings_nbr);
	map_array = parsing_map(fd, map_array, player);
	close(fd);
	return (map_array);
}
/*
int		main(int ac, char **av)
{
	int			i;
	t_map		map_info;
	char		**map_array = NULL;
	t_player	player;

	(void)ac;
	map_array = parsing_cub(av[1], &map_info, map_array, &player);
	printf("%-14s %i %i\n", "resolution:", map_info.width, map_info.height);
	printf("%-14s %x\n%-14s %x\n", "floor:", map_info.floor,
			"ceiling:", map_info.ceiling);
	printf("%24s\n%24s\n%24s\n%24s\n%24s\n", (char *)map_info.sprite.north,
			(char *)map_info.sprite.south, (char *)map_info.sprite.west,
			(char *)map_info.sprite.east, (char *)map_info.sprite.item);
	printf("[%f][%f]\n", player.x, player.y);
	i = 0;
	while (map_array[i] != NULL){
		printf("[%2i]%s\n",i, map_array[i]);
		free(map_array[i]);
		i++;
	}
//	printf("[%2i]%s\n",i, map_array[i]);

	free(map_array[i]);
	free(map_array);
	free(map_info.sprite.south);
	free(map_info.sprite.west);
	free(map_info.sprite.east);
	free(map_info.sprite.north);
	free(map_info.sprite.item);
//	exit(1);
}
*/
