/*
 *	conv_x.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:44:43
 *	19/05/19 18:02:55
 */

#include "libft.h"

void	check_flags_x(t_pfs *pfs)
{
	if (pfs->flags & SPACE)
		pfs->flags &= ~SPACE;
	if (pfs->flags & PLUS)
		pfs->flags &= ~PLUS;
}

static void	conv_x_helper(t_pfs *pfs, char *str, char *sign, t_ulli nbr)
{
	int	len_sign;

	len_sign = 2;
	if (nbr == 0)
		len_sign = 0;
	if (nbr == 0 && !pfs->precision)
		conv_str(pfs, "", "", 0);
	if (nbr == 0 && !pfs->precision)
		return ;
	if (!(pfs->flags & SPECIAL))
		len_sign = 0;
	if (pfs->flags & MINUS)
		conv_str_minus(pfs, str, sign, len_sign);
	else
		conv_str(pfs, str, sign, len_sign);
}

void	conv_x(t_pfs *pfs)
{
	char	str[32];
	char	*sign;
	t_ulli	nbr;

	if (pfs->length & LONG || pfs->length & LONG_LONG)
		nbr = va_arg(pfs->ap, t_ulli);
	else
		nbr = va_arg(pfs->ap, unsigned int);
	nbr = conv_length_un(nbr, pfs);
	check_flags_x(pfs);
	sign = HASH_LO;
	if (pfs->type == 8)
		sign = HASH_UP;
	if (pfs->type == 8)
		pf_itoa_un(nbr, str, 16, 1);
	else
		pf_itoa_un(nbr, str, 16, 0);
	conv_x_helper(pfs, str, sign, nbr);
}
