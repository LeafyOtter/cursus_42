/*
 *	ft_lstdelone.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:00:01
 *	18/05/18 16:00:05
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (lst->content)
		(*del)(lst->content);
	free(lst);
}
