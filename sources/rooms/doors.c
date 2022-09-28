/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doors.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:33:51 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/28 16:35:49 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

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

void	ft_draw_door(char **map, unsigned int room[2][2])
{
	unsigned int	door[2];
	unsigned int	loc;
	unsigned int	width;
	unsigned int	height;

	width = room[1][0] - room[0][0];
	height = room[1][1] - room[0][1];
	while (width != 0)
	{
		ft_generate_door(door, room, width, height);
		if (map[door[0]][door[1]] == '1')
			width = 0;
	}
	map[door[0]][door[1]] = 'T';
}