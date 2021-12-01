/*
 *	ft_strlen.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:58:07
 *	31/05/31 17:19:58
 */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s && s[++i])
		;
	return (i);
}
