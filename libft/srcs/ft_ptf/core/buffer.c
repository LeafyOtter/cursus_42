/*
 *	buffer.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:46:37
 *	19/05/19 18:03:37
 */

#include "libft.h"

/*
 *	@name:		print pfs.index_buffer of pfs.buffer, then reset both;
 *	@return:	void;
 *	@param1:	pfs struct, containing pfs.index_buffer
 *				and pfs.ptr_buffer;
 */

void	print_buffer(t_pfs *pfs)
{
	int	tmp;

	tmp = write(pfs->fd, pfs->ptr_buffer, pfs->index_buffer);
	if (tmp == -1)
		return ;
	pfs->return_value += pfs->index_buffer;
	pfs->index_buffer = 0;
}

/*
 *	@name:		puts str in buffer, print buffer if full;
 *	@return:	void;
 *	@param1:	pfs struct, containing pfs.index_buffer
 *				and pfs.ptr_buffer;
 *	@param2:	string to insert in buffer;
 *	@param3:	length to insert in buffer;
 */

void	put_in_buffer(t_pfs *pfs, char *str, int len)
{
	size_t	len_to_cpy;

	while (len)
	{
		len_to_cpy = len;
		if (len > BUFFER_SIZE - pfs->index_buffer)
			len_to_cpy = BUFFER_SIZE - pfs->index_buffer;
		ft_memcpy(pfs->ptr_buffer + pfs->index_buffer, str, len_to_cpy);
		len -= len_to_cpy;
		pfs->index_buffer += len_to_cpy;
		str += len_to_cpy;
		if (pfs->index_buffer == BUFFER_SIZE)
			print_buffer(pfs);
	}
}
