/*
 *	ft_tolower.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:01:36
 *	18/05/18 17:01:42
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
