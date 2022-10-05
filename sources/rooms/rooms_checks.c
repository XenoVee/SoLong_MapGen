/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:46:54 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/04 17:56:32 by rmaes         ########   odam.nl         */
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

int	check_space(unsigned int room[2][2], t_params *prms)
{
	int	ix;
	int	iy;
	int	c;

	ix = -2;
	iy = -2;
	c = 1;
	while (c)
	{
		if (prms->map[ft_min(ft_max(room[0][0], 0), prms->x)]
			[ft_min(ft_max(room[1][1], 0), prms->y)] == '1')
			return (0);
	}
}
