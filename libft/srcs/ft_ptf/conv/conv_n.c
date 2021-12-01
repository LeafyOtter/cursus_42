/*
 *	conv_n.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:43:24
 *	19/05/19 18:02:25
 */

#include "libft.h"

void	conv_n(t_pfs *pfs)
{
	void	*ptr;

	ptr = va_arg(pfs->ap, void *);
	print_buffer(pfs);
	*(int *)ptr = pfs->return_value;
}

void	conv_percent(t_pfs *pfs)
{
	pfs->precision = PVAR_NSET;
	if (pfs->flags & MINUS)
		conv_str_minus(pfs, "%", 0, 0);
	else
		conv_str(pfs, "%", 0, 0);
}
