/*
 *	ft_lstiter.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:00:12
 *	18/05/18 16:00:23
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
