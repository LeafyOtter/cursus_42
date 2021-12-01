/*
 *	markup.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	16/09/21 15:36:56
 *	26/09/21 19:38:34
 */

#include "swap_push.h"

/*
 *	find position of nb in the already sorted array, and write the index.
 *	@1 : pointer to first item of lst
 *	@2 : size of lst
 *	@3 : pointer to first item of sorted array
 *	@4 : size of array
 */

void	lst_index(t_stck_elem *elem,
		size_t stck_size,
		int *array,
		size_t array_size)
{
	size_t		i;
	size_t		j;
	t_stck_elem	*current;

	i = 0;
	current = elem;
	while (i < stck_size)
	{
		j = 0;
		while (current->nb != array[j] && j < array_size)
			j++;
		if (current->nb == array[j])
			current->index = j;
		current = current->next;
		i++;
	}
}

size_t	markup_great(size_t stck_size,
		t_stck_elem *markup_head,
		bool to_write)
{
	size_t			i;
	size_t			to_push_nbr;
	long int		nbr_opt;
	t_stck_elem		*current;

	i = 0;
	current = markup_head;
	nbr_opt = markup_head->nb;
	to_push_nbr = 0;
	while (i++ <= stck_size)
	{
		to_push_nbr++;
		if (to_write)
			current->to_push = true;

		if (current->nb >= nbr_opt)
		{
			nbr_opt = current->nb;
			if (to_write)
				current->to_push = false;
		}
		current = current->next;
	}
	return (to_push_nbr);
}

size_t	markup_index(size_t stck_size,
		t_stck_elem *markup_head,
		bool to_write)
{
	size_t		i;
	size_t		index;
	size_t		to_push_nbr;
	t_stck_elem	*current;

	i = 0;
	to_push_nbr = 0;
	current = markup_head;
	index = markup_head->index;
	while (i++ < stck_size)
	{
		to_push_nbr++;
		if (to_write)
			current->to_push = true;
		if ((index + 1) == current->index || (index == current->index))
		{
			index = current->index;
			if (to_write)
				current->to_push = false;
			to_push_nbr--;
		}
		current = current->next;
	}
	return (to_push_nbr);
}

/*
 *	loop on all elem of stck to find best markup head
 *	best is the one with the higher return from markup
 */

void	get_best_markup_head(t_swap *swap,
		t_stck_elem *head,
		size_t (*markup)(size_t, t_stck_elem *, bool to_write))
{
	size_t		i;
	size_t		stck_size;
	size_t		to_push_opt;
	size_t		to_push_nbr;
	t_stck_elem	*current;

	i = 0;
	stck_size = swap->a->stck_size;
	to_push_opt = -1;
	current = head;
	swap->a->markup_head = head;
	while (i < stck_size)
	{
		to_push_nbr = markup(swap->a->stck_size, current, false);
		if (to_push_nbr < to_push_opt)
		{
			swap->a->markup_head = current;
			to_push_opt = to_push_nbr;
		}
		i++;
		current = current->next;
	}
	swap->a->to_push_nbr = to_push_opt;
	markup(swap->a->stck_size, swap->a->markup_head, true);
//	printf("tpo : %zu mk : %zu\n", to_push_opt, swap->a->markup_head->index);
//	print_stack_debug(swap->a->head, swap->a->stck_size);
}
