/*
 *	math_utils.c
 *	by fire
 *	<loutre@courrier.dev>
 *	11/07/21 17:08:10
 *	17/07/21 16:51:52
 */

#include "fract_oil.h"

double	ft_cabs(t_cplx cplx)
{
	double	ret;

	ret = pow(cplx.rp, 2) + pow(cplx.ip, 2);
	ret = sqrt(ret);
	return (ret);
}
