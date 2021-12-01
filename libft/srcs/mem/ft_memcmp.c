/*
 *	ft_memcmp.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:04:56
 *	18/05/18 16:05:48
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		p1++;
		p2++;
	}
	return (0);
}
