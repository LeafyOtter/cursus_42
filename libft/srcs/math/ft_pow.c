/*
 *	ft_pow.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:01:40
 *	18/05/18 16:03:06
 */

int	ft_pow(int x, unsigned int exponent)
{
	int	pow;

	pow = 1;
	while (exponent)
	{
		if (exponent & 1)
			pow *= x;
		exponent = exponent >> 1;
		x *= x;
	}
	return (pow);
}
