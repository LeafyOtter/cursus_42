/*
 *	ft_lstlast.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:00:27
 *	18/05/18 16:00:32
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
