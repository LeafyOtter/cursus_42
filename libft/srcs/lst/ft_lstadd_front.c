/*
 *	ft_lstadd_front.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 15:59:32
 *	18/05/18 15:59:37
 */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	new->next = *alst;
	*alst = new;
}
