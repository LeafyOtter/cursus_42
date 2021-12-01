/*
 *	ft_strmapi.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:58:11
 *	18/05/18 17:02:47
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	while (ret[i])
	{
		ret[i] = (*f)(i, ret[i]);
		i++;
	}
	return (ret);
}
