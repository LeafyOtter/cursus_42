/*
 *	ft_strncmp.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:58:15
 *	18/05/18 17:02:25
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && --n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
