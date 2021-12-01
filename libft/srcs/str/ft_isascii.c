/*
 *	ft_isascii.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:34:40
 *	18/05/18 16:34:47
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
