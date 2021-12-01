/*
 *	ft_memmove.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:05:13
 *	18/05/18 16:05:16
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*p1;
	const char		*p2;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		p1 = (char *)dest;
		p2 = (const char *)src;
		if (!dest && !src)
			return (dest);
		while (n--)
			p1[n] = p2[n];
	}
	return (dest);
}
