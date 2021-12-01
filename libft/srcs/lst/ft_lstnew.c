/*
 *	ft_lstnew.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:00:49
 *	18/05/18 16:00:53
 */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->next = NULL;
	head->content = data;
	return (head);
}
