/*
 *	parsing_length.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:48:33
 *	19/05/19 18:07:11
 */

#include "libft.h"

int	parsing_length(char *str, t_pfs *pfs)
{
	int	index;

	index = 0;
	while (!ft_strchr(ALL_FLAGS, str[index]))
		index++;
	while (str[index] && (str[index] == 'h' || str[index] == 'l'))
	{
		if (str[index] == 'h')
			pfs->length |= SHORT;
		if (str[index] == 'l')
			pfs->length |= LONG;
		if (str[index + 1] == 'h')
		{
			pfs->length |= CHAR;
			index++;
		}
		if (str[index + 1] == 'l')
		{
			pfs->length |= LONG_LONG;
			index++;
		}
		index++;
	}
	return (index);
}
