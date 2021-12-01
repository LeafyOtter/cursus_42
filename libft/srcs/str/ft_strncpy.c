/*
 *	ft_strncpy.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:58:22
 *	18/05/18 16:58:30
 */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i++ < n && src[i] != '\0')
		dest[i] = src[i];
	while (i++ < n)
		dest[i] = '\0';
	return (dest);
}
