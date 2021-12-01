/*
 *	parsing_flags.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:48:14
 *	19/05/19 18:07:01
 */

#include "libft.h"

/*
 *	@name:		set bytes in the pfs->flags accordingly
 *	@param1:	index of the flags in the FLAGS define.
 *	@param2:	pointer to data struct t_pfs
 */

void	set_flags(size_t i, t_pfs *pfs)
{
	int	array[6];

	array[0] = ZEROPAD;
	array[1] = PLUS;
	array[2] = SPACE;
	array[3] = MINUS;
	array[4] = SPECIAL;
	pfs->flags |= array[i];
}

/*
 *	@name:		parse flags if present
 *	@return:	number of flags present
 *	@param1:	pointer to string to format
 *	@param2:	pointer to data struct t_pfs
 */

int	parsing_flags(char *str, t_pfs *pfs)
{
	int		index;
	size_t	flag_pos;

	index = 0;
	while (!ft_strchr(ALL_FLAGS, str[index]))
		index++;
	while (str[index])
	{
		flag_pos = (size_t)ft_strchr(FLAGS, str[index]);
		if (!flag_pos)
			break ;
		set_flags(flag_pos - (size_t)FLAGS, pfs);
		index++;
	}
	return (index);
}
