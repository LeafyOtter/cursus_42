/*
 *	parsing_utils.c
 *	by fire
 *	<loutre@courrier.dev>
 *	24/07/21 17:06:38
 *	26/09/21 15:52:32
 */

#include "swap_push.h"

void	check_nb(t_stck_elem *lst, long int nb, size_t size)
{
	if (!lst)
		return ;
	while (size--)
	{
		if (lst->nb == nb)
			error_exit(lst);
		lst = lst->next;
	}
}

void	check_valid_input(t_swap *swap, char *str, int tmp)
{
	if (tmp < 0)
		error_exit(swap->a->head);
	while (str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str)
		error_exit(swap->a->head);
}

int	ft_atoli_err(long int *nbr, char **nptr)
{
	int	sign;
	int	ret;

	*nbr = 0;
	ret = 0;
	sign = 1;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == ' ')
		(*nptr)++;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign *= -1;
		(*nptr)++;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		ret = 1;
		*nbr *= 10;
		*nbr += (**nptr - '0') * sign;
		if (*nbr > INT_MAX || *nbr < INT_MIN)
			return (-1);
		(*nptr)++;
	}
	return (ret);
}

void	parsing(t_swap *swap, int ac, char **av)
{
	int			ret_atoli;
	char		*tmp;
	size_t		i;
	long int	nb;

	i = 0;
	while (++i < (size_t)ac)
	{
		while (*i[av] != '\0')
		{
			tmp = i[av];
			ret_atoli = ft_atoli_err(&nb, &i[av]);
			if (ret_atoli <= 0)
				check_valid_input(swap, tmp, ret_atoli);
			else
			{
				check_nb(swap->a->head, nb, swap->a->stck_size);
				lst_add_to_stack(&swap->a->head, &swap->a->stck_size, nb);
			}
		}
	}
}
