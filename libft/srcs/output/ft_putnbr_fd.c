/*
 *	ft_putnbr_fd.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:27:44
 *	18/05/18 16:28:30
 */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	int		nbr;
	char	num[11];

	nbr = nb;
	i = 10;
	num[10] = '0';
	if (nb == -2147483648)
	{
		num[i--] = '8';
		nb /= 10;
	}
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		num[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (nbr < 0)
		num[i] = '-';
	else if (nbr != 0)
		i++;
	write(fd, &num[i], 11 - i);
}
