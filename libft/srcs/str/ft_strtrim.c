/*
 *	ft_strtrim.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:59:35
 *	18/05/18 17:00:49
 */

#include "libft.h"

static	int	is_charset(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*ptr;

	if (!s1)
		return (NULL);
	while (is_charset(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && is_charset(s1[len - 1], set))
		len--;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i] && i < len)
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}
