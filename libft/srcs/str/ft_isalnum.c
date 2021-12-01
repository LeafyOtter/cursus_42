/*
 *	ft_isalnum.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:30:33
 *	18/05/18 16:34:12
 */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
