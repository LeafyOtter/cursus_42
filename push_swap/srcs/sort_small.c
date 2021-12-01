/*
 *	sort_small.c
 *	by fire
 *	<loutre@courrier.dev>
 *	06/09/21 17:58:23
 *	26/09/21 15:18:21
 */

#include "swap_push.h"

/*
1 2 3 /
1 3 2 sa ra
2 1 3 sa
2 3 1 rra
3 1 2 ra
3 2 1 sa rra
*/

void	sort_three(t_swap *swap, t_stck_elem *a)
{
	long	sec;
	long	lst;

	sec = a->next->nb;
	lst = a->prec->nb;
	if (a->nb < sec && sec > lst && a->nb < lst)
	{
		move_swap(swap, move_a);
		move_rotate(swap, move_a);
	}
	else if (a->nb > sec && sec < lst && a->nb < lst)
		move_swap(swap, move_a);
	else if (a->nb < sec && sec > lst && a->nb > lst)
		move_reverse_rotate(swap, move_a);
	else if (a->nb > sec && sec < lst && a->nb > lst)
		move_rotate(swap, move_a);
	else if (a->nb > sec && sec > lst && a->nb > lst)
	{
		move_swap(swap, move_a);
		move_reverse_rotate(swap, move_a);
	}
}
/*
void    insert(t_swap *swap, t_stck *a, t_stck *b)
{
    long        nbr_a;
    long        nbr_b;

    while (b->stck_size)
    {
        if (b)
            move_x(&move_reverse_rotate, swap, move_b, nbr_b * - 1);
        else
            move_x(&move_rotate, swap, move_b, nbr_b);
        move_push(swap, move_a);
    }
	printf("test\n");
    nbr_a = get_number_move(a, find_elem(a, 0));
	printf("%li\n", nbr_a);
    if (nbr_a > 0)
        move_x(&move_reverse_rotate, swap, move_a, ft_abs(nbr_a));
    else
        move_x(&move_rotate, swap, move_a, nbr_a + 1);

}

//void	sort_five(t_swap *swap, t_stck *a, t_stck *b)
//{
//	move_push(swap, move_b);
//	move_push(swap, move_b);
//	sort_three(swap, swap->a->head);
//	insert(swap, a, b);
//}
*/
