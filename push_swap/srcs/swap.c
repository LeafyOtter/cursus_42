/*
 *	swap.c
 *	by fire
 *	<loutre@courrier.dev>
 *	24/07/21 18:01:06
 *	26/09/21 19:25:57
 */

#include "swap_push.h"

/*
 *	why the f*** is the swapped elem called blue?
 *	it's because it was the color of the block on the diagram i used,
 *	and i had no idea, sorry;
 */

void	fswap(t_stck_elem **top)
{
	t_stck_elem	*blue;
	t_stck_elem	*head;

	head = (*top);
	blue = head->next;
	head->prec->next = blue;
	blue->next->prec = head;
	blue->prec = head->prec;
	head->prec = blue;
	head->next = blue->next;
	blue->next = head;
	(*top) = blue;
}

void	move_swap(t_swap *swap, t_move move)
{
	swap->nbr_move++;
	if (move == move_a)
	{
		if (!(swap->a->stck_size > 1))
			return ;
		fswap(&swap->a->head);
		write(1, "sa\n", 3);
	}
	else if (move == move_b)
	{
		if (!(swap->b->stck_size > 1))
			return ;
		fswap(&swap->b->head);
		write(1, "sb\n", 3);
	}
	else if (move == move_ab)
	{
		if (!(swap->a->stck_size > 1))
			return ;
		if (!(swap->b->stck_size > 1))
			return ;
		fswap(&swap->a->head);
		fswap(&swap->b->head);
		write(1, "ss\n", 3);
	}
}
