/*
 *	ft_strlcat.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:57:54
 *	18/05/18 16:57:57
 */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < size && *dst)
		dst++;
	while (src[j])
		j++;
	if (i == size)
		return (i + j);
	j = -1;
	while (src[++j])
	{
		if (j < size - i - 1)
			*dst++ = src[j];
	}
	*dst = '\0';
	return (i + j);
}
