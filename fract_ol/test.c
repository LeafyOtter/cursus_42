



#include <math.h>
#include <stdio.h>

typedef struct s_cplx
{
	double rp;
	double ip;
}	t_cplx;

#define MAX_ITER 100

double	ft_cabs(t_cplx cplx)
{
	double ret;

	ret = pow(cplx.rp, 2) + pow(cplx.ip, 2);
	ret = sqrt(ret);
	return (ret);
}

t_cplx	ft_cpow(t_cplx cplx, t_cplx c)
{
	t_cplx ret;

	ret.rp = cplx.rp * cplx.rp - cplx.ip * cplx.ip + c.rp;
	ret.ip = 2 * cplx.rp * cplx.ip + c.ip;
	return (ret);
}

int iterate_on_px(int x, int y)
{
	t_cplx	crnt;
	t_cplx	next;
    t_cplx  c;
    int     iteration;

    iteration = 0;
	c = (t_cplx){(double)x, (double)y};
    crnt = (t_cplx){0, 0};
    // calculate complexe number at start

    while (iteration < MAX_ITER)
    {
//		crnt = ft_cpow(crnt, c);
		next.rp = crnt.rp * crnt.rp - crnt.ip * crnt.ip + c.rp;
		next.ip = 2 * crnt.rp * crnt.ip + c.ip;
		crnt = next;
//		crnt = ft_cpow(crnt, c);
        if (ft_cabs(crnt) > 4.0f)
            break ;
        iteration++;
    }
	printf("[%3i][%9.3f][%9.3f][%3i][%3i]\n", iteration, crnt.rp, crnt.ip, x, y);
    return (iteration);
}

int main(void)
{
	for (int y = -21; y < 21; y++)
	{
		for (int x = -21; x < 21; x++)
		{
			iterate_on_px(x, y);
		}
	}
}
