/*
 *	rotate.c
 *	by fire
 *	<loutre@courrier.dev>
 *	24/07/21 21:08:26
 *	26/09/21 15:10:04
 */

#include "swap_push.h"

static void	rotate(t_stck_elem **begin)
{
	if (!*begin)
		return ;
	if ((*begin)->next)
		*begin = (*begin)->next;
}

static void	reverse_rotate(t_stck_elem **begin)
{
	if (!*begin)
		return ;
	if ((*begin)->next)
		*begin = (*begin)->prec;
}

void	move_rotate(t_swap *swap, t_move move)
{
	if (move == move_a)
	{
		rotate(&swap->a->head);
		write(1, "ra\n", 3);
		swap->nbr_move++;
	}
	if (move == move_b)
	{
		rotate(&swap->b->head);
		write(1, "rb\n", 3);
		swap->nbr_move++;
	}
	if (move == move_ab)
	{
		rotate(&swap->a->head);
		rotate(&swap->b->head);
		write(1, "rr\n", 3);
		swap->nbr_move++;
	}
}

void	move_reverse_rotate(t_swap *swap, t_move move)
{
	if (move == move_a)
	{
		reverse_rotate(&swap->a->head);
		write(1, "rra\n", 4);
		swap->nbr_move++;
	}
	if (move == move_b)
	{
		reverse_rotate(&swap->b->head);
		write(1, "rrb\n", 4);
		swap->nbr_move++;
	}
	if (move == move_ab)
	{
		reverse_rotate(&swap->a->head);
		reverse_rotate(&swap->b->head);
		write(1, "rrr\n", 4);
		swap->nbr_move++;
	}
}
