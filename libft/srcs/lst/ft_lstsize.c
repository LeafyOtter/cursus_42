/*
 *	ft_lstsize.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:01:03
 *	18/05/18 16:01:10
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
