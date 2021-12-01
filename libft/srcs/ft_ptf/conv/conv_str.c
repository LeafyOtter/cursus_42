/*
 *	conv_str.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:44:20
 *	19/05/19 18:02:48
 */

#include "libft.h"

void	conv_str_minus(t_pfs *pfs, char *str, char *sign, int len_sign)
{
	int		len;
	int		p_len;
	int		padlen;

	p_len = 0;
	padlen = 0;
	len = ft_strlen(str);
	if (pfs->precision >= len)
		p_len = pfs->precision - len;
	if (pfs->width >= len)
		padlen = pfs->width - p_len - len - len_sign;
	if (sign)
		put_in_buffer(pfs, sign, len_sign);
	while (p_len--)
		put_in_buffer(pfs, "0", 1);
	put_in_buffer(pfs, str, len);
	while (padlen > 0 && padlen--)
		put_in_buffer(pfs, " ", 1);
}

void	conv_str(t_pfs *pfs, char *str, char *sign, int len_sign)
{
	int		len;
	int		p_len;
	int		padlen;
	char	pad;

	pad = ' ';
	p_len = 0;
	padlen = 0;
	len = ft_strlen(str);
	if (pfs->flags & ZEROPAD)
		pad = '0';
	if (pfs->precision >= len)
		p_len = pfs->precision - len;
	if (pfs->width >= len)
		padlen = pfs->width - p_len - len - len_sign;
	if (sign && pfs->flags & ZEROPAD)
		put_in_buffer(pfs, sign, len_sign);
	while (padlen > 0 && padlen--)
		put_in_buffer(pfs, &pad, 1);
	if (sign && !(pfs->flags & ZEROPAD))
		put_in_buffer(pfs, sign, len_sign);
	while (p_len--)
		put_in_buffer(pfs, "0", 1);
	put_in_buffer(pfs, str, len);
}
