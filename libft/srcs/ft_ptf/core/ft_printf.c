/*
 *	ft_printf.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:47:29
 *	25/07/21 00:27:31
 */

#include "libft.h"

/*
 *	@name:		parse @param1 into a buffer, calls /wip/ when % is found;
 *	@return:	number of characters written;
 *	@param1:	string to parse & format;
 *	@param2:	structure with ptr to buffer, ptr to arg, several pfs,
 *				and return value;
 */

static void	parsing(const char *str, t_pfs *pfs)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			tmp = parsing_format((char *)(str + i + 1), pfs);
			if (tmp)
				conversions(pfs);
			if (tmp)
				i += tmp;
			if (!tmp)
				put_in_buffer(pfs, (char *)str + i, 1);
			if (!tmp)
				i++;
		}
		else
		{
			put_in_buffer(pfs, (char *)str + i, 1);
			i++;
		}
	}
	print_buffer(pfs);
}

/*
 *	ft_printf:	initialize several struct then calls parsing;
 *	@return:	number of characters written;
 *	@param1:	string to format & write;
 *	@param2:	use of stdarg;
 */

int	ft_printf(const char *str, ...)
{
	char	buffer[BUFFER_SIZE];
	t_pfs	struct_pfs;

	struct_pfs.fd = FD;
	struct_pfs.index_buffer = VAR_NSET;
	struct_pfs.return_value = VAR_NSET;
	struct_pfs.ptr_buffer = buffer;
	clear_struct(&struct_pfs);
	va_start(struct_pfs.ap, str);
	parsing(str, &struct_pfs);
	va_end(struct_pfs.ap);
	return (struct_pfs.return_value);
}
