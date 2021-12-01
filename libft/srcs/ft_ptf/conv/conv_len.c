/*
 *	conv_len.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:43:04
 *	19/05/19 18:02:15
 */

#include "libft.h"

long long int	conv_length(long long int nbr, t_pfs *pfs)
{
	size_t	ret;

	if (pfs->length & CHAR)
		ret = (char)nbr;
	if (pfs->length & CHAR)
		return (ret);
	if (pfs->length & SHORT)
		ret = (short)nbr;
	if (pfs->length & SHORT)
		return (ret);
	if (pfs->length & LONG_LONG)
		ret = (long long)nbr;
	if (pfs->length & LONG_LONG)
		return (ret);
	if (pfs->length & LONG)
		ret = (long)nbr;
	if (pfs->length & LONG)
		return (ret);
	return (nbr);
}

t_ulli	conv_length_un(t_ulli nbr, t_pfs *pfs)
{
	t_ulli	ret;

	if (pfs->length & CHAR)
		ret = (unsigned char)nbr;
	if (pfs->length & CHAR)
		return (ret);
	if (pfs->length & SHORT)
		ret = (unsigned short)nbr;
	if (pfs->length & SHORT)
		return (ret);
	if (pfs->length & LONG_LONG)
		ret = (t_ulli)nbr;
	if (pfs->length & LONG_LONG)
		return (ret);
	if (pfs->length & LONG)
		ret = (unsigned long int)nbr;
	if (pfs->length & LONG)
		return (ret);
	return (nbr);
}
