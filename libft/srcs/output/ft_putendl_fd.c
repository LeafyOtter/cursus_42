/*
 *	ft_putendl_fd.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:27:43
 *	18/05/18 16:28:07
 */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
