/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/22 18:04:42 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

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

void	ft_rooms(char **map, t_params *prms, unsigned int nrooms)
{
	printf("%d\n", nrooms);
}

void	ft_fill_map(char **map, t_params *prms)
{
	ft_outer_walls(map);
	ft_rooms(map, prms, rand() % (1 + ((prms->x / 8) * (prms->y / 8) / 2)));
}
