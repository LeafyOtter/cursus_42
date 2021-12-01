/*
 *	ft_strnstr.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:59:09
 *	18/05/18 16:59:18
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	size_t	i_b;
	size_t	i_l;
	size_t	i_sl;

	if (!(little[0]))
		return ((char *)big);
	i_b = -1;
	while (big[++i_b] && i_b < l)
	{
		if (big[i_b] == little[0])
		{
			i_sl = i_b;
			i_l = -1;
			while (big[++i_l + i_sl] && i_sl + i_l < l)
			{
				if (little[i_l] != big[i_sl + i_l])
					break ;
				if (!(little[i_l + 1]))
					return ((char *)&big[i_sl]);
			}
		}
	}
	return (NULL);
}
