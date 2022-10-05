/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:46:54 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/05 17:05:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

int	chcky(t_params *prms, unsigned int ix, unsigned int iy, int mod)
{
	unsigned int	b;

	if (iy <= 1 && mod < 0)
		return (1);
	iy += mod;
	if (iy + 1 >= prms->y)
		return (1);
	b = 0;
	if (prms->map[ix][iy] == '1' || prms->map[ix][iy] == 'c'
		|| prms->map[ix][iy] == 'D')
			b++;
	if (prms->map[ix - 1][iy] == '1' || prms->map[ix - 1][iy] == 'D'
		|| prms->map[ix - 1][iy] == 'c')
			b++;
	if (prms->map[ix + 1][iy] == '1' || prms->map[ix + 1][iy] == 'D'
		|| prms->map[ix + 1][iy] == 'c')
			b++;
	if (b > 1)
		return (1);
	return (0);
}

int	chckx(t_params *prms, unsigned int ix, unsigned int iy, int mod)
{
	unsigned int	b;

	if (ix <= 1 && mod < 0)
		return (1);
	ix += mod;
	if (ix + 1 >= prms->x)
		return (1);
	b = 0;
	if (prms->map[ix][iy] == '1' || prms->map[ix][iy] == 'c'
		|| prms->map[ix][iy] == 'D')
			b++;
	if (prms->map[ix][iy - 1] == '1' || prms->map[ix][iy - 1] == 'D'
		|| prms->map[ix][iy - 1] == 'c')
			b++;
	if (prms->map[ix][iy + 1] == '1' || prms->map[ix][iy + 1] == 'D'
		|| prms->map[ix][iy + 1] == 'c')
			b++;
	if (b > 1)
		return (1);
	return (0);
}

static int	check_space_ext(int c, int d,
	unsigned int room[2][2], t_params *prms)
{
	int	ix;
	int	iy;

	iy = -1;
	ix = -1;
	while (iy < 2)
	{
		while (ix < 2)
		{
			if (prms->map[ft_btw(room[0 + c][0] + ix, prms->x, 0)]
					[ft_btw(room[0 + d][1] + iy, prms->y, 0)] == '1')
				return (0);
			ix++;
		}
		ix = -2;
		iy++;
	}
	return (1);
}

int	check_space(unsigned int room[2][2], t_params *prms)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (c < 2)
	{
		while (d < 2)
		{
			if (!check_space_ext(c, d, room, prms))
				return (0);
			d++;
		}
		d = 0;
		c++;
	}
	return (1);
}
