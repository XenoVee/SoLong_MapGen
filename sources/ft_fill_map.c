/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/27 16:52:48 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"
#include <math.h>

void	ft_cleanup(char **map)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (map[ix])
	{
		while (map[ix][iy])
		{
			if (map[ix][iy] == 'T')
			map[ix][iy] = ' ';
			iy++;
		}
		ix++;
		iy = 0;
	}
}

void	ft_outer_walls(char **map)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (map[ix])
	{
		while (map[ix][iy])
		{
			if (ix == 0 || iy == 0 || map[ix + 1] == NULL
				|| map[ix][iy + 1] == 0)
				map[ix][iy] = '1';
			iy++;
		}
	ix++;
	iy = 0;
	}
}

void	ft_fill_map(char **map, t_params *prms)
{
	unsigned int	avg;

	avg = (prms->x + prms->y) / 2;
	ft_outer_walls(map);
	ft_rooms(map, prms, rand() % ft_max(avg / 4, 0));
	ft_cleanup(map);
}
