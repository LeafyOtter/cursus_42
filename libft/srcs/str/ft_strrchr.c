/*
 *	ft_strrchr.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:59:24
 *	18/05/18 16:59:26
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	if ((char)c == '\0')
		return (ft_strchr(s, c));
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s++;
	}
	return (ret);
}
