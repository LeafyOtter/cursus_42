/*
 *	ft_isprint.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:34:59
 *	18/05/18 16:35:07
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
