/*
 *	format.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:47:06
 *	19/05/19 18:04:16
 */

#include "libft.h"

/*
 *	@name:		clear flags which overrides each other;
 *	@param1:	pointer to struct where flags are located;
 */

void	remove_overriding_flags(t_pfs *pfs)
{
	if (pfs->precision >= 0 && pfs->type != 0 && pfs->type != 1
		&& !(pfs->type >= 10 && pfs->type <= 13))
		pfs->flags &= ~ZEROPAD;
	if (pfs->flags & MINUS)
		pfs->flags &= ~ZEROPAD;
	if (pfs->flags & PLUS)
		pfs->flags &= ~SPACE;
}

/*
 *	@name:		set variables in the pfs struct to 0;
 *	@param1:	pointer to struct to clear;
 */

void	clear_struct(t_pfs *pfs)
{
	pfs->flags = VAR_NSET;
	pfs->width = VAR_NSET;
	pfs->precision = PVAR_NSET;
	pfs->length = VAR_NSET;
	pfs->type = VAR_NSET;
}

/*
 * @name:		parse flags given in str;
 * @return:		number of characters parsed;
 * @param1:		string with flags to parse;
 * @param2:		struct used to store format flags;
 */

int	parsing_format(char *str, t_pfs *pfs)
{
	int	index;
	int	tmp;

	index = 0;
	index += parsing_flags(str, pfs);
	index += parsing_width(str + index, pfs);
	index += parsing_precision(str + index, pfs);
	index += parsing_length(str + index, pfs);
	tmp = parsing_type(str + index, pfs);
	if (pfs->type > 13)
		return (0);
	index += tmp;
	return (index + 1);
}
