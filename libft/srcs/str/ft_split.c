/*
 *	ft_split.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:42:48
 *	18/05/18 16:56:52
 */

#include "libft.h"

/*
**	Length of next word.
*/

static size_t	strlen_split(const char *s, char c)
{
	size_t	i;

	i = -1;
	while (s[++i] && s[i] != c)
		;
	return (i + 1);
}

/*
**	Allocate and copy next word.
*/

static char	*strdup_split(const char *s, char c)
{
	char	*p;
	size_t	i;

	i = -1;
	p = (char *)malloc(sizeof(char) * strlen_split(s, c));
	if (!p)
		return (NULL);
	while (s[++i] && s[i] != c)
		p[i] = s[i];
	p[i] = '\0';
	return (p);
}

/*
**	Function auxiliary to split, it fills tab, and clear if there is an error.
*/

static char	**auxf_split(const char *s, char c, char **tab)
{
	int			i;
	ssize_t		i_tab;

	i = -1;
	i_tab = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			tab[i_tab++] = strdup_split(&s[i], c);
			if (!tab[i_tab])
			{
				while (--i_tab >= 0)
					free(tab[i_tab]);
				free(tab);
				return (NULL);
			}
			i += strlen_split(&s[i], c) - 2;
		}
	}
	tab[i_tab] = NULL;
	return (tab);
}

/*
**	Functions couting the number of words, allocate tab, then call auxf_split
*/

char	**ft_split(const char *s, char c)
{
	int		i;
	int		cnt;
	char	**tab;

	i = 0;
	cnt = 1;
	if (!s)
		return (NULL);
	if (s[0] == c || !s[0])
		cnt = 0;
	while (s[0] && s[++i])
		if (s[i - 1] == c && s[i] != c)
			cnt++;
	tab = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!tab)
		return (NULL);
	tab = auxf_split(s, c, tab);
	if (!tab)
		return (NULL);
	return (tab);
}
