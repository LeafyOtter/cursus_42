/*
 *	conv_p.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:44:03
 *	19/05/19 18:02:39
 */

#include "libft.h"

void	conv_p(t_pfs *pfs)
{
	char	str[32];
	size_t	ptr;

	ptr = (size_t)va_arg(pfs->ap, void *);
	pf_itoa((long long int)ptr, str, 16, 0);
	if (pfs->precision == 0 && ptr == 0)
	{
		if (pfs->flags & MINUS)
			conv_str_minus(pfs, "", "0x", 2);
		else
			conv_str(pfs, "", "0x", 2);
	}
	else if (pfs->flags & MINUS)
		conv_str_minus(pfs, str, "0x", 2);
	else
		conv_str(pfs, str, "0x", 2);
}
