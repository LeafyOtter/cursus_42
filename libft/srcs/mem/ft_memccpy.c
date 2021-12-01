/*
 *	ft_memccpy.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:04:33
 *	18/05/18 16:04:45
 */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	const char		*p2;

	i = -1;
	p1 = (unsigned char *)dest;
	p2 = (const char *)src;
	if (!dest && !src)
		return (dest);
	while (++i < n)
	{
		p1[i] = p2[i];
		if (p1[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
