/*
 *	ft_strchr.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:57:08
 *	18/05/18 16:57:17
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (unsigned char)*s != (unsigned char)c)
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
