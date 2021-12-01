/*
 *	ft_lstclear.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 15:59:40
 *	18/05/18 15:59:45
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
