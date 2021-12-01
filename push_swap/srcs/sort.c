/*
 *	sort.c
 *	by wind
 *	<loutre@courrier.dev>
 *	26/09/21 18:10:40
 *	26/09/21 18:10:40
 */

#include "swap_push.h"

/*	WHILE stack A has elements with "false" value in "Keep in Stack A" field
 *	      IF sa (swap a) is needed
 *	            perform sa (swap a) command
 *	            update markup
 *	      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
 *	            perform pb (push b) command
 *	      ELSE
 *	            perform ra (rotate a) command
 */

size_t	check_swap(t_swap *swap,
		size_t (*markup)(size_t, t_stck_elem *, bool))
{
	size_t	new_markup;

//	printf("\t--------------------------------------------------\n");
//	print_stack_debug(swap->a->head, swap->a->stck_size);
	fswap(&swap->a->head);
	new_markup = markup(swap->a->stck_size, swap->a->markup_head, true);
//	printf("new : %zu old : %zu\n", new_markup, swap->a->to_push_nbr);
//	print_stack_debug(swap->a->head, swap->a->stck_size);
	fswap(&swap->a->head);
	new_markup = markup(swap->a->stck_size, swap->a->markup_head, true);
//	printf("\t[------------------------------------------------]\n");
//	exit (-1);
	if (new_markup < swap->a->to_push_nbr)
		return (1);
	return (0);
}

void	stack_a(t_swap *swap, t_stck *a,
		size_t (*markup)(size_t, t_stck_elem *, bool))
{
	t_stck_elem	*current;

	current = a->head;
	while (a->to_push_nbr)
	{
		if (check_swap(swap, markup))
		{
			move_swap(swap, move_a);
			swap->a->to_push_nbr = markup(swap->a->stck_size, current, true);
			current = current->next;
		}
		else if (current->to_push)
		{
			move_push(swap, move_b);
			current = a->head;
			a->to_push_nbr--;
		}
		else
		{
			move_rotate(swap, move_a);
			current = current->next;
		}
	}
	stack_b(swap, a, swap->b);
}

/*
 *	WHILE stack B is not empty
 *	      choose element in stack B for moving to stack A
 *	      move stack A and stack B to prepare them for pa (push a) with chosen element
 *	      perform pa (push a) command
 *
 */

t_stck_elem	*get_move_elem(t_stck *a, t_stck *b, long *nbr_a, long *nbr_b)
{
	size_t		i;
	long		best_move;
	t_stck_elem	*current;
	t_stck_elem	*elem_to_push;

	i = 0;
	current = b->head;
	best_move = LONG_MAX;
	while (b->stck_size > i)
	{
		(*nbr_b) = get_number_move(b, current);
		(*nbr_a) = get_number_move(a, find_elem(a, current->index));
		if ((ft_abs(*nbr_b) + ft_abs(*nbr_a)) < best_move)
		{
			best_move = ft_abs(*nbr_b) + ft_abs(*nbr_a);
			elem_to_push = current;
		}
		i++;
		current = current->next;
	}
	(*nbr_b) = get_number_move(b, elem_to_push);
	(*nbr_a) = get_number_move(a, find_elem(a, elem_to_push->index));
	return (elem_to_push);
}

void	stack_b(t_swap *swap, t_stck *a, t_stck *b)
{
	long		nbr_a;
	long		nbr_b;

	while (b->stck_size)
	{
		get_move_elem(a, b, &nbr_a, &nbr_b);
		if (nbr_a < 0)
			move_x(&move_reverse_rotate, swap, move_a, nbr_a * - 1);
		else
			move_x(&move_rotate, swap, move_a, nbr_a);
		if (nbr_b < 0)
			move_x(&move_reverse_rotate, swap, move_b, nbr_b * - 1);
		else
			move_x(&move_rotate, swap, move_b, nbr_b);
		move_push(swap, move_a);
	}
	nbr_a = get_number_move(a, find_elem(a, 0));
	if (nbr_a < 0)
		move_x(&move_reverse_rotate, swap, move_a, (nbr_a * - 1));
	else
		move_x(&move_rotate, swap, move_a, nbr_a);

}
