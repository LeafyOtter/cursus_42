/*
 *	ft_strjoin.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:57:48
 *	18/05/18 16:57:52
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char	*ret;

	index = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!(ret))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		ret[index++] = s1[i];
	while (s2[++j])
		ret[index++] = s2[j];
	ret[index] = '\0';
	return (ret);
}
