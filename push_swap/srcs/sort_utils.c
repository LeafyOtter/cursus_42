/*
 *	sort_utils.c
 *	by wind
 *	<loutre@courrier.dev>
 *	27/09/21 00:54:00
 *	27/09/21 00:54:00
 */

#include "swap_push.h"

long	get_number_move(t_stck *stck, t_stck_elem *elem)
{
	long int	i;
	t_stck_elem	*current;

	i = 0;
	current = stck->head;
	while (current != elem && stck->stck_size > (size_t)i)
	{
		i++;
		current = current->next;
	}
	if (!i || i == 1)
		return (i);
	if (i > ((long long int)stck->stck_size >> 1))
		i -= (long long int)stck->stck_size;
	return (i);
}

t_stck_elem	*find_elem(t_stck *stck, size_t index)
{
	t_stck_elem	*current;

	current = stck->markup_head;
	if (index < current->index)
	{
		while (index < current->prec->index && \
				current->index > current->prec->index)
			current = current->prec;
	}
	else
	{
		while (index > current->index && current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}
