/*
 *	ft_itoa.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:35:19
 *	18/05/18 17:07:30
 */

#include "libft.h"
#include <stdio.h>

static	int	len_int(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (i);
	return (1 + len_int(n / 10));
}

void	itoa_helper(long *nb, int *sign, int *size_ptr)
{
	*nb *= -1;
	*sign *= -1;
	*size_ptr += 1;
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size_ptr;
	int		sign;
	long	nb;

	nb = (long)n;
	size_ptr = len_int(nb);
	sign = 1;
	if (nb < 0)
		itoa_helper(&nb, &sign, &size_ptr);
	ptr = (char *)malloc(sizeof(char) * (size_ptr + 1));
	if (!ptr)
		return (NULL);
	ptr[size_ptr] = '\0';
	while (size_ptr-- > 0)
	{
		ptr[size_ptr] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign < 0)
		ptr[0] = '-';
	return (ptr);
}
