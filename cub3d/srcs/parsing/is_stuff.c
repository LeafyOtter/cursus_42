/*
 *	is_stuff.c
 *	by leaf
 *	<loutre@courrier.dev>
 *	19/05/19 16:04:06
 *	13/06/13 17:00:55
 */

#include "wolf.h"

int	is_direction(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_notwall(int c)
{
	if (is_direction(c) || NOTWALL[0] == c)
		return (1);
	return (0);
}

int	is_valid(int c)
{
	if (c == '1' || is_notwall(c))
		return (1);
	return (0);
}
