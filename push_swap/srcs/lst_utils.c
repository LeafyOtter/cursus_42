/*
 *	lst_utils.c
 *	by fire
 *	<loutre@courrier.dev>
 *	24/07/21 15:16:35
 *	26/09/21 15:11:38
 */

#include "swap_push.h"

t_stck_elem	*lst_new_elem(long int nb)
{
	t_stck_elem	*new;

	new = malloc(sizeof(t_stck_elem));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	lst_join_begin_last(t_stck_elem *first, size_t n)
{
	t_stck_elem	*last;

	last = lst_get_last(first, n);
	first->prec = last;
	last->next = first;
}

t_stck_elem	*lst_get_last(t_stck_elem *stck, size_t n)
{
	size_t	i;

	i = 0;
	while (i < (n - 1))
	{
		stck = stck->next;
		i++;
	}
	return (stck);
}

void	lst_create_first_elem(t_stck_elem **begin, long int nb)
{
	(*begin) = lst_new_elem(nb);
	if (!*begin)
		error_exit(*begin);
	(*begin)->prec = NULL;
}

void	lst_add_to_stack(t_stck_elem **begin, size_t *size_stck, long int nb)
{
	t_stck_elem	*lst;
	t_stck_elem	*new;

	if (!*begin)
	{
		lst_create_first_elem(begin, nb);
		(*size_stck)++;
		return ;
	}
	lst = lst_get_last(*begin, *size_stck);
	new = lst_new_elem(nb);
	if (!new)
		error_exit(*begin);
	lst->next = new;
	new->prec = lst;
	(*size_stck)++;
}
