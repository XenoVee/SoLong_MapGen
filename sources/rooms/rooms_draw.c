/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_draw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:53:04 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/28 16:45:06 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

static void	ft_draw_walls(char **map, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if (map[ix][iy] != 'T')
	{
		if ((ix == room[0][0] || ix == room[1][0]) && (iy == room[0][1]
			|| iy == room[1][1]))
				map[ix][iy] = 'c';
		else if ((ix == room[0][0] || ix == room[1][0]))
			map[ix][iy] = '1';
		else if ((iy == room[1][1] || iy == room[0][1]))
			map[ix][iy] = '1';
	}
}

static void	ft_draw_infill(char **map, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if ((ix > room[0][0] && iy > room[0][1])
		&& (ix < room[1][0] && iy < room[1][1]))
			map[ix][iy] = 'T';
}

void	ft_draw_room(unsigned int room[2][2], char **map, t_params *prms)
{
	int				f;
	unsigned int	ix;
	unsigned int	iy;

	f = 1;
	ix = room[0][0];
	iy = room[0][1];
	while (ix - 1 != room[1][0] || iy != room[1][1])
	{
		ft_draw_walls(map, room, ix, iy);
		ft_draw_infill(map, room, ix, iy);
		if (ix == room[1][0] && iy < room[1][1])
		{
			ix = room[0][0];
			iy++;
		}
		else
			ix++;
	}
	ft_draw_door(map, room);
}
