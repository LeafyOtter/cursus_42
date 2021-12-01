/*
 *	ft_isalpha.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:34:29
 *	18/05/18 16:34:38
 */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
