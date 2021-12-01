/*
 *	quicksort.c
 *	by fire
 *	<loutre@courrier.dev>
 *	25/07/21 04:09:43
 *	25/07/21 04:27:22
 */

#include "swap_push.h"

int	check_stack_b(t_swap *swap, long mid_value)
{
	size_t		i;
	t_stck_elem	*head;

	i = 0;
	head = swap->b->head;
	while (i < swap->b->stck_size)
	{
		if (head->nb >= mid_value)
			return (1);
		i++;
		head = head->next;
	}
	return (0);
}

int	check_stack_a(t_stck *a, long mid)
{
	size_t		i;
	t_stck_elem	*head;

	i = 0;
	head = a->head;
	while (i < a->stck_size)
	{
		if (head->nb <= mid)
			return (1);
		i++;
		head = head->next;
	}
	return (0);
}

void	compensate(t_swap *swap,
		t_stck *stck,
		t_move move,
		int counter)
{
	if (counter < 0)
		return ;
	if (counter > (int)((stck->stck_size / 2)))
	{
		while (counter++ != (int)stck->stck_size)
			move_rotate(swap, move);
	}
	else
	{
		while (counter-- > 0)
			move_reverse_rotate(swap, move);
	}
}

void	sort_b(t_swap *swap, int low, int high)
{
	int			mid;
	int			len;
	int			counter;
	long		mid_value;

	counter = 0;
	if (low > high)
		return ;
	if (is_sorted(swap))
		return ;
	mid = (low + high) / 2;
	len = high - mid + 1;
	mid_value = swap->array[mid];
	while (check_stack_b(swap, mid_value))
	{
		if (swap->b->stck_size && swap->b->stck_size != 1
				&& len == 1 && swap->b->head->next->nb >= mid_value)
			move_swap(swap, move_b);
		if (swap->b->head->nb < mid_value)
		{
			move_rotate(swap, move_b);
			counter++;
		}
		else
		{
			len--;
			move_push(swap, move_a);
		}
	}
	compensate(swap, swap->b, move_b, counter);
	sort_a(swap, mid, high);
	sort_b(swap, low, mid - 1);
}

void	sort_a(t_swap *swap, int low, int high)
{
	int			mid;
	int			len;
	int			counter;
	long		mid_value;

	counter = 0;
	if (low >= high)
		return ;
	if (is_sorted(swap))
		return ;
	mid = (low + high) / 2;
	len = mid - low + 1;
	mid_value = swap->array[mid];
	while (check_stack_a(swap->a, mid_value))
	{
		if (len == 1 && swap->a->head->next->nb <= mid_value)
			move_swap(swap, move_a);
		if (swap->a->head->nb > mid_value)
		{
			move_rotate(swap, move_a);
			counter++;
		}
		else
		{
			len--;
			move_push(swap, move_b);
		}
	}
	compensate(swap, swap->a, move_a, counter);
	sort_a(swap, mid + 1, high);
	sort_b(swap, low, mid);
}

void	quick_sort(t_swap *swap)
{
	sort_a(swap, 0, swap->size_array - 1);
}
