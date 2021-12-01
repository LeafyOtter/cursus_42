/*
 *	color.c
 *	by wind
 *	<loutre@courrier.dev>
 *	12/06/12 15:30:08
 *	12/06/12 15:34:12
 */

#include "wolf.h"

int	encode_rgb(
		int red,
		int green,
		int blue)
{
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return (red << 16 | green << 8 | blue);
}

int	apply_shader(
		int color,
		double dist)
{
	int		i;
	t_rgb	original;
	t_rgb	new;

	i = 6;
	original.red = (color & (0xFF << 16)) >> 16;
	original.gre = (color & (0xFF << 8)) >> 8;
	original.blu = (color & 0xFF);
	new.red = original.red * (i / dist);
	new.gre = original.gre * (i / dist);
	new.blu = original.blu * (i / dist);
	new.red = (original.red < new.red) * (original.red - new.red) + new.red;
	new.blu = (original.blu < new.blu) * (original.blu - new.blu) + new.blu;
	new.gre = (original.gre < new.gre) * (original.gre - new.gre) + new.gre;
	return (encode_rgb(new.red, new.gre, new.blu));
}
