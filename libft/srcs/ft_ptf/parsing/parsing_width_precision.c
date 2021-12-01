/*
 *	parsing_width_precision.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:49:20
 *	19/05/19 18:07:24
 */

#include "libft.h"

int	pf_atoi(char *str, int *value)
{
	int	index;
	int	flag;

	flag = 1;
	index = 0;
	*value = 0;
	if (str[index] == '-')
		flag = -1;
	if (str[index] == '-')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
		*value = (*value * 10) + str[index++] - '0';
	*value *= flag;
	return (index);
}

int	parsing_width(char *str, t_pfs *pfs)
{
	int	index;

	index = 0;
	while (!ft_strchr(ALL_FLAGS, str[index]))
		index++;
	if (str[index] == '*')
	{
		pfs->width = va_arg(pfs->ap, int);
		if (pfs->width < 0)
			pfs->flags |= MINUS;
		if (pfs->width < 0)
			pfs->width *= -1;
		return (index + 1);
	}
	index += pf_atoi(str, &pfs->width);
	return (index);
}

int	parsing_precision(char *str, t_pfs *pfs)
{
	int	temp;
	int	index;

	index = 0;
	while (!ft_strchr(ALL_FLAGS, str[index]))
		index++;
	if (str[index] == '.')
	{
		index++;
		if (str[index] == '*')
		{
			temp = va_arg(pfs->ap, int);
			pfs->precision = temp;
			if (temp < 0)
				pfs->precision = PVAR_NSET;
			return (index + 1);
		}
		temp = pf_atoi(str + index, &pfs->precision);
		if (!temp)
			pfs->precision = 0;
		return (index + temp);
	}
	return (index);
}
