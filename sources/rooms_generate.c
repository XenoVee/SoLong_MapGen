/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_generate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 22:33:38 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/27 22:36:36 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	ft_generate_door(unsigned int door[1], unsigned int room[2][2]
	, unsigned int width, unsigned int height)
{
	unsigned int	loc;

	loc = rand() % (width + height) * 2;
	if (loc > (width * 2) + height)
	{
		door[0] = room[0][0];
		door[1] = loc - (width * 2) + height -1;
	}
	if (loc > width + height)
	{
		door[0] = room[0][0] + loc - width - height - 1;
		door[1] = room[1][1];
	}
	if (loc > width)
	{
		door[0] = room[1][0];
		door[1] = room[0][1] + loc - width - 1;
	}
	if (loc < width)
	{
		door[0] = room[0][0] + loc - 1;
		door[1] = room[0][1];
	}
}

// room[][] syntax: room[coords 0/ coords 1][x/ y]
// with coord 0 being the top left and coord 1 being the bottom right corner
// and with x coords being 0 and y coords being 1
// roomsize: [0] = north wall distance from mid point, [1] is east wall,
// [2] is west wall, [3] is south wall
void	ft_generate_room(unsigned int room[2][2], t_params *prms)
{
	unsigned int	roomsize[4];
	unsigned int	mid[2];

	mid[0] = 4 + rand() % (prms->x - 8);
	mid[1] = 4 + rand() % (prms->y - 8);
	roomsize[0] = ft_min(1 + rand() % (mid[0] - 1), prms->x / 8);
	roomsize[1] = ft_min(1 + rand() % (mid[1] - 1), prms->y / 8);
	roomsize[2] = ft_min(1 + rand() % (prms->x - mid[0] - 1), prms->x / 8);
	roomsize[3] = ft_min(1 + rand() % (prms->y - mid[1] - 1), prms->y / 8);
	room[0][0] = mid[0] - roomsize[0];
	room[0][1] = mid[1] - roomsize[1];
	room[1][0] = mid[0] + roomsize[2];
	room[1][1] = mid[1] + roomsize[3];
}
