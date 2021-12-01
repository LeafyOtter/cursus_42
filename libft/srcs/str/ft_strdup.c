/*
 *	ft_strdup.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:57:37
 *	18/05/18 16:57:45
 */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!(p))
		return (NULL);
	while (s[++j])
		p[j] = s[j];
	p[j] = '\0';
	return (p);
}
