/*
 *	ft_atoi.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:29:35
 *	24/07/21 17:12:29
 */

int	ft_atoi(const char *nptr)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr *= 10;
		nbr += (*nptr - '0') * sign;
		nptr++;
	}
	return (nbr);
}

/*
 *	increment the pointer once a number is read
 */

int	ft_atoi_skip(char **nptr)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == ' ')
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign *= -1;
		(*nptr)++;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		nbr *= 10;
		nbr += (**nptr - '0') * sign;
		(*nptr)++;
	}
	return (nbr);
}
