/*
 *	ft_memcpy.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:05:05
 *	18/05/18 16:05:08
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*p1;
	const char		*p2;

	i = -1;
	p1 = (char *)dest;
	p2 = (const char *)src;
	if (!dest && !src)
		return (dest);
	while (++i < n)
		p1[i] = p2[i];
	return (dest);
}
