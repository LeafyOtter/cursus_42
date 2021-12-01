/*
 *	ft_substr.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:00:55
 *	18/05/18 17:01:29
 */

#include "libft.h"

static	size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	index;
	size_t	tmp;

	index = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	tmp = ft_min(ft_strlen(&s[start]), len);
	ret = (char *)malloc(sizeof(char) * (tmp + 1));
	if (!ret)
		return (NULL);
	while (s[start] && index < len)
		ret[index++] = s[start++];
	ret[index] = '\0';
	return (ret);
}
