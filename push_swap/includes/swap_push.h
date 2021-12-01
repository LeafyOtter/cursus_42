#ifndef SWAP_PUSH_H
# define SWAP_PUSH_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define COLOR_RED     "\033[0:31m"
# define COLOR_GREEN   "\033[0:32m"
# define COLOR_YELLOW  "\033[0:33m"
# define COLOR_BLUE    "\033[0:34m"
# define COLOR_MAGENTA "\033[0:35m"
# define COLOR_CYAN    "\033[0:36m"
# define COLOR_RESET   "\033[0m"

# define ERROR -1;

typedef enum e_move
{
	move_a,
	move_b,
	move_ab
}	t_move;

typedef struct s_qs
{
	int	partition;
	int	size;
	int	*array;
}	t_qs;

typedef struct s_stck_elem
{
	long int			nb;
	bool				to_push;
	size_t				index;
	struct s_stck_elem	*prec;
	struct s_stck_elem	*next;
}	t_stck_elem;

typedef struct s_stck
{
	size_t		stck_size;
	size_t		to_push_nbr;
	t_stck_elem	*head;
	t_stck_elem	*markup_head;
}	t_stck;

typedef struct s_swap
{
	int		*array;
	size_t	size_array;
	t_stck	*a;
	t_stck	*b;
	size_t	nbr_move;
}	t_swap;

/*
 * lst_utils.c
 */

void		lst_add_to_stack(t_stck_elem **begin,
				size_t *size_stck,
				long int nb);
void		lst_create_first_elem(t_stck_elem **begin, long int nb);
t_stck_elem	*lst_get_last(t_stck_elem *stck, size_t n);
void		lst_join_begin_last(t_stck_elem *first, size_t n);
t_stck_elem	*lst_new_elem(long int nb);

/*
 *	main.c
 */

void		error_exit(t_stck_elem *lst);
void		print_stack(t_swap *swap);
void		print_stack_debug(t_stck_elem *head, size_t stck_size);

/*
 *	markup.c
 */

void		get_best_markup_head(t_swap *swap,
				t_stck_elem *head,
				size_t(*markup)(size_t, t_stck_elem *, bool));
void		lst_index(t_stck_elem *stck,
				size_t s_stck,
				int *array,
				size_t s_array);
size_t		markup_index(size_t stck_size,
				t_stck_elem *markup_head,
				bool to_write);
size_t		markup_great(size_t stck_size,
				t_stck_elem *markup_head,
				bool to_write);

/*
 *	parsing_utils.c
 */
void		check_nb(t_stck_elem *lst, long int nb, size_t size);
void		check_valid_input(t_swap *swap, char *str, int tmp);
int			ft_atoli_err(long int *nbr, char **nptr);
void		parsing(t_swap *swap, int ac, char **av);

/*
 *	push.c
 */

void		move_push(t_swap *swap, t_move move);

/*
 *	quicksort.c
 */

void		quick_sort(t_swap *swap);
void		sort_a(t_swap *swap, int low, int high);

/*
 *	rotate.c
 */

void		move_rotate(t_swap *swap, t_move move);
void		move_reverse_rotate(t_swap *swap, t_move move);

/*
 *	sort.c
 */

t_stck_elem	*get_move_elem(t_stck *a, t_stck *b, long *nbr_a, long *nbr_b);
void		stack_a(t_swap *swap, t_stck *a,
				size_t (*markup)(size_t, t_stck_elem *, bool));
void		stack_b(t_swap *swap, t_stck *a, t_stck *b);

/*
 *	sort_small.c
 */

void		sort_three(t_swap *swap, t_stck_elem *a);
void		sort_five(t_swap *swap, t_stck *a, t_stck *b);

/*
 *	sort_utils.c
 */

t_stck_elem	*find_elem(t_stck *stck, size_t index);
long		get_number_move(t_stck *stck, t_stck_elem *elem);

/*
 *	swap.c
 */

void		fswap(t_stck_elem **top);
void		move_swap(t_swap *swp, t_move move);

/*
 *	presort.c
 */

int			*init_pre_quicksort(t_stck_elem *lst,
				size_t size_lst, size_t *size_array);

/*
 *	utils.c
 */

void		destroy_lst(t_stck_elem **stck);
long		ft_abs(long nb);
void		ft_putnbr_fd(int nb, int fd);
int			is_sorted(t_swap *swap);
void		move_x(void (*move)(t_swap *, t_move),
				t_swap *swap, t_move mv, long nbr);

#endif
