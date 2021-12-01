/*
 *	ft_toupper.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:01:43
 *	18/05/18 17:01:50
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}
