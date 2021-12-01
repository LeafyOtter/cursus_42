/*
 *	ft_lstmap.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:00:39
 *	18/05/18 17:06:27
 */

#include "libft.h"

void	*function_helper(t_list *begin, void *tmp, void (*del)(void *))
{
	ft_lstclear(&begin, del);
	del(tmp);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*new;
	void	*tmp;

	if (!f || !del)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		if (!tmp)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		new = ft_lstnew(tmp);
		if (!new)
			return (function_helper(begin, tmp, del));
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}
