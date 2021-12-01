/*
 *	libft.h
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:04:28
 *	24/07/21 17:12:39
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
 *			Functions and defines required for gnl.
 */

# define TO_FREE 1
# define TO_KEEP 0
# define GNL_ERROR -1

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

int		get_next_line(const int fd, char **line);

char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_substr_free(char *s, unsigned int i, size_t l, int fs);
int		is_newline(char *str);

/*
 *			Functions and defines required for ft_printf/
 */

# define VAR_NSET 0
# define PVAR_NSET -1

# define FD 1

# define TYPES "cspdiuoxXnfge%"
# define FLAGS "0+ -#"
# define ALL_FLAGS "cspdiuoxX%-0.*nfgelh# +123456789"
# define BASE_LO "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"
# define HASH_LO "0x"
# define HASH_UP "0X"

# define UPPER 1
# define LOWER 0

# define ZEROPAD    1
# define PLUS       2
# define SPACE      4
# define MINUS      8
# define SPECIAL    16

# define SHORT      1
# define CHAR       2
# define LONG       4
# define LONG_LONG  8

typedef struct s_pfs
{
	int		flags;
	int		width;
	int		precision;
	int		length;
	int		type;
	int		index_buffer;
	int		return_value;
	int		fd;
	char	*ptr_buffer;
	va_list	ap;
}	t_pfs;

# define T_LLI long long int
typedef unsigned long long int	t_ulli;

int		ft_printf(const char *str, ...);

int		parsing_format(char *str, t_pfs *pfs);
void	init_struct(t_pfs *pfs);
void	clear_struct(t_pfs *pfs);
void	print_buffer(t_pfs *pfs);
void	put_in_buffer(t_pfs *pfs, char *str, int len);
int		pf_itoa(long long int n, char *s, int b_s, int upper);
void	pf_itoa_un(t_ulli n, char *s, int b_s, int upper);
int		parsing_flags(char *str, t_pfs *pfs);
int		parsing_width(char *str, t_pfs *pfs);
int		parsing_precision(char *str, t_pfs *pfs);
int		parsing_length(char *str, t_pfs *pfs);
int		parsing_type(char *str, t_pfs *pfs);
void	remove_overriding_flags(t_pfs *pfs);
void	conv_c(t_pfs *pfs);
void	conv_s(t_pfs *pfs);
void	conv_p(t_pfs *pfs);
void	conv_d_i(t_pfs *pfs);
void	conv_d_i(t_pfs *pfs);
void	conv_o(t_pfs *pfs);
void	conv_u(t_pfs *pfs);
void	conv_x(t_pfs *pfs);
void	conv_x(t_pfs *pfs);
void	conv_n(t_pfs *pfs);
void	conv_percent(t_pfs *pfs);
void	conversions(t_pfs *pfs);
void	conv_str(t_pfs *pfs, char *str, char *sign, int len_sign);
void	conv_str_minus(t_pfs *pfs, char *str, char *sign, int l_s);
T_LLI	conv_length(long long int nbr, t_pfs *pfs);
t_ulli	conv_length_un(t_ulli nbr, t_pfs *pfs);

/*
 *			Functions manipulating linked lists.
 */

void	ft_lstadd_back(t_list **alst, t_list *new_elem);
void	ft_lstadd_front(t_list **alst, t_list *new_elem);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*
 *			Functions manipulating memory.
 */

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*
 *			Functions for maths.
 */

int		ft_pow(int x, unsigned int exponent);

/*
 *			Functions for printing/outputs
 */

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*
 *			Functions to f*** over the norm v3.
 */

size_t	csa(void *ewe, size_t owo);
int		fternary(int c, int a, int b);

/*
 *			Functions for manipulating strings
 */

int		ft_atoi(const char *str);
int		ft_atoi_skip(char **str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, int n);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t l);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
