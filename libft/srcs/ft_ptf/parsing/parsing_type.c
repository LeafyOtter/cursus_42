/*
 *	parsing_type.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:49:01
 *	19/05/19 18:07:17
 */

#include "libft.h"

int	parsing_type(char *str, t_pfs *pfs)
{
	char	*flag_pos;

	flag_pos = ft_strchr(TYPES, str[0]);
	pfs->type = flag_pos - (char *)TYPES;
	return (1);
}
