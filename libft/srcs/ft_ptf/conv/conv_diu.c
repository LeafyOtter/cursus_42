/*
 *	conv_diu.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:41:44
 *	19/05/19 18:01:38
 */

#include "libft.h"

void	conv_u(t_pfs *pfs)
{
	char	str[32];
	t_ulli	nbr;

	if (pfs->length & LONG || pfs->length & LONG_LONG)
		nbr = va_arg(pfs->ap, t_ulli);
	else
		nbr = va_arg(pfs->ap, unsigned int);
	nbr = conv_length_un(nbr, pfs);
	pf_itoa_un(nbr, str, 10, 0);
	if (nbr == 0 && pfs->precision == 0)
		conv_str(pfs, "", NULL, 0);
	else if (pfs->flags & MINUS)
		conv_str_minus(pfs, str, NULL, 0);
	else
		conv_str(pfs, str, NULL, 0);
}

int	i_hate_the_norm(char sign)
{
	if (sign)
		return (1);
	return (0);
}

void	conv_d_i(t_pfs *pfs)
{
	char			str[32];
	char			sign;
	int				sign_len;
	long long int	nbr;

	if (pfs->length & LONG || pfs->length & LONG_LONG)
		nbr = va_arg(pfs->ap, long long int);
	else
		nbr = va_arg(pfs->ap, int);
	nbr = conv_length(nbr, pfs);
	sign = 0;
	pf_itoa(nbr, str, 10, 0);
	if (nbr < 0)
		sign = '-';
	if (pfs->flags & PLUS && nbr >= 0)
		sign = '+';
	else if (pfs->flags & SPACE && nbr >= 0)
		sign = ' ';
	sign_len = i_hate_the_norm(sign);
	if (nbr == 0 && pfs->precision == 0)
		str[0] = '\0';
	if (pfs->flags & MINUS)
		conv_str_minus(pfs, str, &sign, sign_len);
	else
		conv_str(pfs, str, &sign, sign_len);
}
