/*
 *	pf_itoa.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:45:07
 *	19/05/19 18:03:02
 */

#include "libft.h"

static int	ft_nbrlen_un(t_ulli n, int base_size)
{
	if (n < 0)
		n *= -1;
	if (n < (t_ulli)base_size)
		return (1);
	return (1 + ft_nbrlen_un(n / base_size, base_size));
}

static int	ft_nbrlen(long long int n, int base_size)
{
	if (n < 0)
		n *= -1;
	if (n < base_size)
		return (1);
	return (1 + ft_nbrlen(n / base_size, base_size));
}

void	pf_itoa_un(t_ulli nbr, char *src, int base_size, int up)
{
	int		i;
	char	*base;

	base = BASE_LO;
	if (up)
		base = BASE_UP;
	i = ft_nbrlen_un(nbr, base_size);
	src[i] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (i--)
	{
		src[i] = base[nbr % base_size];
		nbr /= base_size;
	}
}

int	pf_itoa(long long int nbr, char *src, int base_size, int up)
{
	int		i;
	int		j;
	char	*base;

	base = BASE_LO;
	if (up)
		base = BASE_UP;
	i = ft_nbrlen(nbr, base_size);
	j = 1;
	src[i] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (i--)
	{
		src[i] = base[nbr % base_size];
		nbr /= base_size;
	}
	return (j);
}
