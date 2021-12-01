/*
 *	ft_isspace.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:35:09
 *	18/05/18 16:35:16
 */

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}
