/*
 *	ft_strcpy.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:57:18
 *	18/05/18 16:57:27
 */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i++])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
