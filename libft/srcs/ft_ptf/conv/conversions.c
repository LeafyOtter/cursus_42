/*
 *	conversions.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	18/05/18 17:42:25
 *	19/05/19 18:02:09
 */

#include "libft.h"

void	conversions(t_pfs *pfs)
{
	void	(*conv_ptr_arr[14])(t_pfs *);

	conv_ptr_arr[0] = &conv_c;
	conv_ptr_arr[1] = &conv_s;
	conv_ptr_arr[2] = &conv_p;
	conv_ptr_arr[3] = &conv_d_i;
	conv_ptr_arr[4] = &conv_d_i;
	conv_ptr_arr[5] = &conv_u;
	conv_ptr_arr[6] = &conv_o;
	conv_ptr_arr[7] = &conv_x;
	conv_ptr_arr[8] = &conv_x;
	conv_ptr_arr[9] = &conv_n;
	conv_ptr_arr[13] = &conv_percent;
	if (pfs->type >= 10 && pfs->type <= 12)
		return ;
	if (pfs->type < 0 || pfs->type > 13)
		return ;
	remove_overriding_flags(pfs);
	conv_ptr_arr[pfs->type](pfs);
	clear_struct(pfs);
}

/*
**	conv_ptr_arr[10] = &conv_f;
**	conv_ptr_arr[11] = &conv_g;
**	conv_ptr_arr[12] = &conv_e;
*/
