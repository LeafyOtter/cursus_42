/*
 *	main.c
 *	by fire
 *	<loutre@courrier.dev>
 *	24/07/21 14:01:18
 *	26/09/21 19:33:42
 */

#include "swap_push.h"

void	error_exit(t_stck_elem *lst)
{
	t_stck_elem	*tmp;

	if (lst && lst->prec)
	{
		tmp = lst->prec;
		tmp->next = NULL;
	}
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	write(1, "Error\n", 6);
	exit(1);
}

void	print_stack(t_swap *swap)
{
	size_t		i;
	size_t		size;
	t_stck_elem	*tmp;

	size = swap->a->stck_size;
	tmp = swap->a->head;
	i = 0;
	if (size != 1)
	{
		printf("debug : swap.a [%p]\n\tswap.b [%p]\n\t[a]||", swap->a, swap->b);
		while (i++ < size)
		{
			printf("[%02li]", tmp->nb);
			tmp = tmp->next;
		}
	}
	size = swap->b->stck_size;
	if (size != 1)
	{
		tmp = swap->b->head;
		i = 0;
		printf("\n\t[b]||");
		while (i++ < size)
		{
			printf("[%02li]", tmp->nb);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

void	print_stack_debug(t_stck_elem *head, size_t s_stck)
{
	size_t		i;
	t_stck_elem	*current;

	i = 0;
	current = head;
	while (i < s_stck)
	{
		printf("\tnb : [% 6li] || index : [%3zu] || to_push : [%s]\n", current->nb, current->index, current->to_push ? COLOR_GREEN"true"COLOR_RESET : COLOR_RED"flse"COLOR_RESET);
		current = current->next;
		i++;
	}
}

#include <fcntl.h>

int	main(int ac, char **av)
{
	t_swap	swap;
	t_stck	a;
	t_stck	b;

	swap = (t_swap){NULL, 0, &a, &b, 0};
	a = (t_stck){0, 0, NULL, NULL};
	b = (t_stck){0, 0, NULL, NULL};
	parsing(&swap, ac, av);
	if (ac == 1 || swap.a->stck_size <= 1)
		return (0);
	lst_join_begin_last(swap.a->head, swap.a->stck_size);
	//	printf("%p %p\n", swap.a, swap.a->prec);
	//	if (swap.size_a >= 90)
	//	if (swap.size_a >= 90)
	//	print_stack(&swap);
	//	print_stack(&swap);
	swap.array = init_pre_quicksort(swap.a->head, \
			swap.a->stck_size, &swap.size_array);
	lst_index(swap.a->head, swap.a->stck_size, swap.array, swap.size_array);
	if (swap.a->stck_size == 3)
		sort_three(&swap, swap.a->head);
//	else if (swap.a->stck_size <= 5)
//		sort_five(&swap, swap.a, swap.b);
	else if (swap.a->stck_size < 50)
	{
		get_best_markup_head(&swap, swap.a->head, &markup_index);
		//		print_stack_debug(swap.a->head, swap.a->stck_size);
		//		printf("markup_head : %li\n", swap.a->markup_head->nb);
		stack_a(&swap, swap.a, &markup_index);
		get_best_markup_head(&swap, swap.a->head, &markup_great);
	}
		else
			quick_sort(&swap);
//	print_stack(&swap);
//	printf("prec %p next %p %li\n", swap.a->head->prec, swap.a->head->next, swap.a->head->nb);
	destroy_lst(&swap.a->head);
	destroy_lst(&swap.b->head);
	free(swap.array);
}
