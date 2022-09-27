/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_draw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:53:04 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/27 22:39:13 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

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

static void	ft_draw_door(char **map, unsigned int room[2][2])
{
	unsigned int	door[2];
	unsigned int	loc;
	unsigned int	width;
	unsigned int	height;

	width = room[1][0] - room[0][0];
	height = room[1][1] - room[0][1];
	while (width != 0)
	{
		printf("%d,%d\n", width, height);
		ft_generate_door(door, room, width, height);
		if (map[door[0]][door[1]] == '1')
			width = 0;
	}
	map[door[0]][door[1]] = 'T';
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

void	ft_rooms(char **map, t_params *prms, unsigned int nrooms)
{
	unsigned int	ix;
	unsigned int	iy;
	unsigned int	room[2][2];

	ix = 0;
	iy = 0;
	while (nrooms > 0)
	{
		ft_generate_room(room, prms);
		printf("room %d:  %d,%d - %d,%d\n", nrooms, room[0][0], room[0][1],
			room[1][0], room[1][1]);
		ft_draw_room(room, map, prms);
		nrooms--;
	}
}
