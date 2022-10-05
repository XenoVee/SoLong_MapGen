/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_draw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:53:04 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/05 16:15:26 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

static void	ft_draw_walls(t_params *prms, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if (prms->map[ix][iy] == '0')
	{
		if ((ix == room[0][0] || ix == room[1][0]) && (iy == room[0][1]
			|| iy == room[1][1]))
				prms->map[ix][iy] = 'c';
		else if ((ix == room[0][0] || ix == room[1][0]))
		{
			if (chckx(prms, ix, iy, -1) || chckx(prms, ix, iy, 1))
					prms->map[ix][iy] = 'T';
			else
				prms->map[ix][iy] = 'W';
		}
		else if ((iy == room[1][1] || iy == room[0][1]))
		{
			if (chcky(prms, ix, iy, -1) || chcky(prms, ix, iy, 1))
				prms->map[ix][iy] = 'T';
			else
				prms->map[ix][iy] = 'W';
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

void	ft_confirm_walls(t_params *prms)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (prms->map[ix])
	{
		while (prms->map[ix][iy])
		{
			if (prms->map[ix][iy] == 'c')
				prms->map[ix][iy] = '1';
			if (prms->map[ix][iy] == 'W')
				prms->map[ix][iy] = '1';
			iy++;
		}
		ix++;
		iy = 0;
	}
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
	ft_confirm_walls(prms);
}
