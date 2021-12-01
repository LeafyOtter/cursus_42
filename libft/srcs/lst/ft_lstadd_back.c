/*
 *	ft_lstadd_back.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 15:59:15
 *	18/05/18 15:59:20
 */

#include "libft.h"

static t_list	*ft_lstlast_tmp(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_elem;

	if (!alst)
		return ;
	if (*alst)
	{
		last_elem = ft_lstlast_tmp(*alst);
		last_elem->next = new;
	}
	else
		*alst = new;
}
