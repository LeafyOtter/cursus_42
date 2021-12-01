/*
 *	parsing.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	15/06/15 17:57:26
 *	17/07/21 16:49:54
 */

#include "fract_oil.h"

int	parsing_arguments(t_fract *fract, int ac, char **av)
{
	int		i;
	int		ret;

	(void)ac;
	i = -1;
	ret = 1;
	while (++i < NB_SET && ret)
		ret = ft_strncmp(fract->array[i], av[1], ft_strlen(fract->array[i]));
	if (ret)
		error_display_list(fract, error_invalid_operand, av[0]);
	return (pow(2, (i - 1)));
}
