/*
 *	conv_o.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:43:57
 *	19/05/19 18:02:30
 */

#include "libft.h"

static void	check_flags_o(t_pfs *pfs)
{
	if (pfs->flags & SPACE)
		pfs->flags &= ~SPACE;
	if (pfs->flags & PLUS)
		pfs->flags &= ~PLUS;
}

void	conv_o(t_pfs *pfs)
{
	char	str[32];
	t_ulli	nbr;

	if (pfs->length & LONG || pfs->length & LONG_LONG)
		nbr = va_arg(pfs->ap, t_ulli);
	else
		nbr = va_arg(pfs->ap, unsigned int);
	nbr = conv_length_un(nbr, pfs);
	check_flags_o(pfs);
	pf_itoa(nbr, str, 8, 0);
	if (pfs->flags & SPECIAL && (pfs->precision < (int)ft_strlen(str)))
	{
		if (pfs->flags & MINUS)
			conv_str_minus(pfs, str, "0", 1);
		else
			conv_str(pfs, str, "0", 1);
		return ;
	}
	if (pfs->flags & MINUS)
		conv_str_minus(pfs, str, NULL, 0);
	else
		conv_str(pfs, str, NULL, 0);
}
