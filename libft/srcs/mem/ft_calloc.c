/*
 *	ft_calloc.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 16:03:45
 *	18/05/18 16:04:13
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
