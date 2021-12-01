/*
 *	ft_strlcpy.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:57:59
 *	18/05/18 16:58:04
 */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = -1;
	if (size != 0)
	{
		while (src[++i] && (size_t)i < (size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
