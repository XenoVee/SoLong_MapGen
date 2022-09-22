/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 20:52:31 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	ft_fill_map(char **map)
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
			// else if (map[ix][iy] != '0')
			// 	map[ix][iy] = '0';
			iy++;
		}
		ix++;
		iy = 0;
	}
}
