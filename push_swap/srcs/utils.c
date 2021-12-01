/*
 *	utils.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	03/09/21 03:34:03
 *	26/09/21 20:57:48
 */

#include "swap_push.h"

void	destroy_lst(t_stck_elem **elem)
{
	t_stck_elem	*tmp;

	if (!elem || !(*elem))
		return ;
	if ((*elem)->prec)
		(*elem)->prec->next = NULL;
	while (*elem)
	{
		tmp = (*elem)->next;
		free(*elem);
		*elem = tmp;
	}
	*elem = NULL;
}

long	ft_abs(long nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}


void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	int		nbr;
	char	num[11];

	nbr = nb;
	i = 10;
	num[10] = '0';
	if (nb == -2147483648)
	{
		num[i--] = '8';
		nb /= 10;
	}
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		num[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (nbr < 0)
		num[i] = '-';
	else if (nbr != 0)
		i++;
	write(fd, &num[i], 11 - i);
}

int	is_sorted(t_swap *swap)
{
	size_t		i;
	t_stck_elem	*current;

	i = 0;
	current = swap->a->head;
	if (swap->b->stck_size != 0)
		return (0);
	while (i < swap->a->stck_size)
	{
		if (current->nb > current->next->nb)
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

void	move_x(void (*move)(t_swap *, t_move),
		t_swap *swap, t_move mv, long nbr)
{
	while (nbr-- > 0)
		move(swap, mv);
}
