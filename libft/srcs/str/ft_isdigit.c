/*
 *	ft_isdigit.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:34:49
 *	18/05/18 16:34:56
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
