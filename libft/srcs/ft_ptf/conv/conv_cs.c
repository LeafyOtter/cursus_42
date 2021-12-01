/*
 *	conv_cs.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:45:59
 *	19/05/19 18:00:56
 */

#include "libft.h"

void	conv_c(t_pfs *pfs)
{
	int		len;
	int		padlen;
	char	c;
	char	pad;

	pad = ' ';
	c = (char)va_arg(pfs->ap, int);
	len = 1;
	if (pfs->width < len)
		put_in_buffer(pfs, &c, len);
	if (pfs->width < len)
		return ;
	padlen = pfs->width - len;
	if (pfs->flags & ZEROPAD)
		pad = '0';
	if (!(pfs->flags & MINUS))
		while (padlen--)
			put_in_buffer(pfs, &pad, len);
	put_in_buffer(pfs, &c, len);
	if (pfs->flags & MINUS)
		while (padlen--)
			put_in_buffer(pfs, &pad, len);
}

static void	print_null_pointer(t_pfs *pfs, char *str)
{
	int		len;
	int		padlen;
	char	pad;

	pad = ' ';
	padlen = 0;
	len = ft_strlen(str);
	if (pfs->flags & ZEROPAD)
		pad = '0';
	if (pfs->precision >= len)
		pfs->precision = len;
	if (pfs->precision < 0)
		pfs->precision = len;
	if (pfs->width > pfs->precision)
		padlen = pfs->width - pfs->precision;
	if (!(pfs->flags & MINUS))
		while (padlen--)
			put_in_buffer(pfs, &pad, 1);
	if (pfs->precision)
		put_in_buffer(pfs, str, pfs->precision);
	if (pfs->flags & MINUS)
		while (padlen--)
			put_in_buffer(pfs, &pad, 1);
}

static void	conv_s_helper(t_pfs *pfs, char *str, int padlen, int len)
{
	char	pad;

	pad = ' ';
	if (!(pfs->flags & MINUS) && pfs->flags & ZEROPAD)
		pad = '0';
	if (!(pfs->flags & MINUS))
		while (padlen--)
			put_in_buffer(pfs, &pad, 1);
	put_in_buffer(pfs, str, len);
	if (pfs->flags & MINUS)
		while (padlen--)
			put_in_buffer(pfs, &pad, 1);
}

void	conv_s(t_pfs *pfs)
{
	int		len;
	int		padlen;
	char	*str;

	str = va_arg(pfs->ap, char *);
	if (!str)
		print_null_pointer(pfs, "(null)");
	if (!str)
		return ;
	len = ft_strlen(str);
	if ((pfs->precision < len && pfs->precision != -1) || !pfs->precision)
		len = pfs->precision;
	if (pfs->width < len)
		put_in_buffer(pfs, str, len);
	if (pfs->width < len)
		return ;
	padlen = pfs->width - len;
	conv_s_helper(pfs, str, padlen, len);
}
