/*
 *	ft_putstr_fd.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:27:44
 *	18/05/18 16:27:59
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
