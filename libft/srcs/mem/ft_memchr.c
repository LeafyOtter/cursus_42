/*
 *	ft_memchr.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:04:48
 *	18/05/18 16:04:50
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = -1;
	p = (unsigned char *)s;
	while (++i < n)
		if (p[i] == (unsigned char)c)
			return (&p[i]);
	return (NULL);
}
