/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 22:33:38 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/05 18:08:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

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
	roomsize[0] = ft_min(2 + rand() % (mid[0] - 2), ft_max(prms->x / 8, 2));
	roomsize[1] = ft_min(2 + rand() % (mid[1] - 2), ft_max(prms->y / 8, 2));
	roomsize[2] = ft_min(2 + rand() % (prms->x - mid[0] - 2), prms->x / 8);
	roomsize[3] = ft_min(2 + rand() % (prms->y - mid[1] - 2), prms->y / 8);
	room[0][0] = mid[0] - roomsize[0];
	room[0][1] = mid[1] - roomsize[1];
	room[1][0] = mid[0] + roomsize[2];
	room[1][1] = mid[1] + roomsize[3];
}

void	ft_rooms(t_params *prms, unsigned int nrooms)
{
	unsigned int	ix;
	unsigned int	iy;
	unsigned int	room[2][2];
	int				l;

	ix = 0;
	iy = 0;
	while (nrooms > 0)
	{
			l = 0;
		while (l == 0)
		{
			ft_generate_room(room, prms);
			if (check_space(room, prms))
				l++;
		}
		printf("room %d:  %d,%d - %d,%d\n", nrooms, room[0][0], room[0][1],
			room[1][0], room[1][1]);
		ft_draw_room(room, prms);
		nrooms--;
	}
}
