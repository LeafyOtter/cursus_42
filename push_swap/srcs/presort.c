/*
 *	presort.c
 *	by fire
 *	<loutre@courrier.dev>
 *	25/07/21 02:28:52
 *	26/09/21 15:15:44
 */

#include "swap_push.h"

static void	swap(t_qs *qs, int num1, int num2)
{
	int	tmp;

	tmp = num1[qs->array];
	num1[qs->array] = num2[qs->array];
	num2[qs->array] = tmp;
}

static int	partition(t_qs *qs, int left, int right, int pivot)
{
	int	left_p;
	int	right_p;

	left_p = left - 1;
	right_p = right;
	while (1)
	{
		while ((++left_p)[qs->array] < pivot)
			;
		while (right_p > 0 && (--right_p)[qs->array] > pivot)
			;
		if (left_p >= right_p)
			break ;
		else
			swap(qs, left_p, right_p);
	}
	swap(qs, left_p, right);
	return (left_p);
}

static void	quick_sort_(t_qs *qs, int left, int right)
{
	int	pivot;

	if (right - left <= 0)
		return ;
	else
	{
		pivot = right[qs->array];
		qs->partition = partition(qs, left, right, pivot);
		quick_sort_(qs, left, qs->partition - 1);
		quick_sort_(qs, qs->partition + 1, right);
	}
}

void	print_array(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(i[array], 1);
		write(1, "|", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	*init_pre_quicksort(t_stck_elem *lst, size_t size_lst, size_t *size_array)
{
	t_qs	qs;
	size_t	i;

	qs.array = (int *)malloc(sizeof(int) * size_lst);
	if (!qs.array)
		return (NULL);
	i = 0;
	while (i < size_lst)
	{
		i[qs.array] = lst->nb;
		lst = lst->next;
		i++;
	}
	qs.size = size_lst - 1;
	quick_sort_(&qs, 0, qs.size);
	*size_array = size_lst;
	return (qs.array);
}

//	print_array(qs.array, size_lst);
