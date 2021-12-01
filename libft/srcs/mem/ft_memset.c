/*
 *	ft_memset.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:05:21
 *	18/05/18 16:05:29
 */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = c;
	return (s);
}
