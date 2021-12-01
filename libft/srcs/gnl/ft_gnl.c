/*
 *	ft_gnl.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 15:53:33
 *	18/05/18 15:53:44
 */

#include "libft.h"

static int	get_line(char **buf, char **line, int index_nl)
{
	if (index_nl == -1)
	{
		if (*buf)
			*line = *buf;
		else
		{
			*line = (char *)malloc(sizeof(char) * 1);
			if (!*line)
				return (GNL_ERROR);
			*line[0] = '\0';
		}
		*buf = NULL;
		return (0);
	}
	*line = ft_substr_free(*buf, 0, index_nl, TO_KEEP);
	*buf = ft_substr_free(*buf, index_nl + 1,
			ft_strlen(*buf) - index_nl, TO_FREE);
	if (!*line || !*buf)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				index_nl;
	int				read_bytes;
	char			read_buffer[BUFFER_SIZE + 1];
	static char		*static_buffer[OPEN_MAX];

	read_bytes = 1;
	if (read(fd, 0, 0) < 0 || fd < 0 || !line || BUFFER_SIZE < 1)
		return (GNL_ERROR);
	index_nl = is_newline(static_buffer[fd]);
	while ((index_nl == -1) && (read_bytes))
	{
		index_nl = is_newline(static_buffer[fd]);
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[read_bytes] = '\0';
		static_buffer[fd] = ft_strjoin_free(static_buffer[fd], read_buffer);
		if (!static_buffer[fd])
			return (GNL_ERROR);
	}
	return (get_line(&static_buffer[fd], line, index_nl));
}
