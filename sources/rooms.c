/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:53:04 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/27 19:23:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

// room[][] syntax: room[coords 0/ coords 1][x/ y]
// with coord 0 being the top left and coord 1 being the bottom right corner
// and with x coords being 0 and y coords being 1
// rmsize: [0] = north wall distance from mid point, [1] is east wall,
// [2] is west wall, [3] is south wall
void	ft_make_room(unsigned int room[2][2], t_params *prms)
{
	unsigned int	rmsize[4];
	unsigned int	mid[2];

	mid[0] = 4 + rand() % (prms->x - 8);
	mid[1] = 4 + rand() % (prms->y - 8);
	rmsize[0] = ft_min(1 + rand() % (mid[0] - 1), prms->x / 8);
	rmsize[1] = ft_min(1 + rand() % (mid[1] - 1), prms->y / 8);
	rmsize[2] = ft_min(1 + rand() % (prms->x - mid[0] - 1), prms->x / 8);
	rmsize[3] = ft_min(1 + rand() % (prms->y - mid[1] - 1), prms->y / 8);
	room[0][0] = mid[0] - rmsize[0];
	room[0][1] = mid[1] - rmsize[1];
	room[1][0] = mid[0] + rmsize[2];
	room[1][1] = mid[1] + rmsize[3];
}

void	ft_draw_room(unsigned int room[2][2], char **map, t_params *prms)
{
	int				f;
	unsigned int	ix;
	unsigned int	iy;

	f = 1;
	ix = room[0][0];
	iy = room[0][1];
	while (f != 0)
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
			else if ((ix > room[0][0] || iy > room[0][1])
				|| (ix < room[1][0] || iy < room[1][1]))
					map[ix][iy] = 'T';
		}
		if (ix < room[1][0])
			ix++;
		else if (ix == room[1][0] && iy < room[1][1])
		{
			ix = room[0][0];
			iy++;
		}
		else if (ix == room[1][0] && iy == room[1][1])
			f = 0;
	}
}

void	ft_rooms(char **map, t_params *prms, unsigned int nrooms)
{
	unsigned int	ix;
	unsigned int	iy;
	unsigned int	room[2][2];

	ix = 0;
	iy = 0;
	while (nrooms > 0)
	{
		ft_make_room(room, prms);
		printf("room %d:  %d,%d - %d,%d\n", nrooms, room[0][0], room[0][1],
			room[1][0], room[1][1]);
		ft_draw_room(room, map, prms);
		nrooms--;
	}
}
