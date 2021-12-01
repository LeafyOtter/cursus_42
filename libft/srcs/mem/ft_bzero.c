/*
 *	ft_bzero.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:03:28
 *	18/05/18 16:03:38
 */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}
