/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_draw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:53:04 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/03 17:53:44 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

static int	chcky(t_params *prms, unsigned int ix, unsigned int iy)
{
	unsigned int	b;

	if (ix + 1 >= prms->x)
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

static int	chckx(t_params *prms, unsigned int ix, unsigned int iy)
{
	unsigned int	b;

	if (iy + 1 >= prms->y)
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

static void	ft_draw_walls(t_params *prms, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if (prms->map[ix][iy] != 'T')
	{
		if ((ix == room[0][0] || ix == room[1][0]) && (iy == room[0][1]
			|| iy == room[1][1]))
				prms->map[ix][iy] = 'c';
		else if ((ix == room[0][0] || ix == room[1][0]))
		{
			if (chckx(prms, ix - 1, iy) || chckx(prms, ix + 1, iy))
			{
				if (prms->map[ix][iy] == '0')
					prms->map[ix][iy] = 'T';
			}
			else
				prms->map[ix][iy] = '1';
		}
		else if ((iy == room[1][1] || iy == room[0][1]))
		{
			if (chcky(prms, ix, iy - 1) || chcky(prms, ix, iy + 1))
				prms->map[ix][iy] = 'T';
			else
				prms->map[ix][iy] = '1';
		}
	}
}

static void	ft_draw_infill(t_params *prms, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if ((ix > room[0][0] && iy > room[0][1])
		&& (ix < room[1][0] && iy < room[1][1])
		&& !(ix >= prms->x || iy >= prms->y))
		if (prms->map[ix][iy] == '0')
			prms->map[ix][iy] = 'T';
}

void	ft_draw_room(unsigned int room[2][2], t_params *prms)
{
	int				f;
	unsigned int	ix;
	unsigned int	iy;

	f = 1;
	ix = room[0][0];
	iy = room[0][1];
	while (ix - 1 != room[1][0] || iy != room[1][1])
	{
		ft_draw_walls(prms, room, ix, iy);
		ft_draw_infill(prms, room, ix, iy);
		if (ix == room[1][0] && iy < room[1][1])
		{
			ix = room[0][0];
			iy++;
		}
		else
			ix++;
	}
	ft_draw_door(prms, room);
}
