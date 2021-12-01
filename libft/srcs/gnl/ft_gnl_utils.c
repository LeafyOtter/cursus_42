/*
 *	ft_gnl_utils.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 15:57:29
 *	18/05/18 17:05:44
 */

#include "libft.h"

int	is_newline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr_free(char *s, unsigned int start, size_t len, int free_s)
{
	size_t	tmp;
	char	*ret;

	if (s)
		tmp = ft_strlen((char *)s);
	if (!s || tmp < start)
	{
		ret = (char *)malloc(sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = 0;
		return (ret);
	}
	if (tmp < start + len)
		len = tmp - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	tmp = -1;
	while (++tmp < len)
		ret[tmp] = s[start + tmp];
	ret[tmp] = '\0';
	if (s && free_s)
		free(s);
	return (ret);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size_buffer;
	char	*ret;

	i = 0;
	j = 0;
	size_buffer = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * size_buffer);
	if (!ret)
		return (NULL);
	while (s1 && s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
	if (s1)
		free(s1);
	return (ret);
}
