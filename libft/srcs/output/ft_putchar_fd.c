/*
 *	ft_putchar_fd.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:27:42
 *	18/05/18 16:28:21
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
