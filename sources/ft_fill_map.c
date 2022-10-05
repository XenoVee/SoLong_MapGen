/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/04 17:26:06 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"
#include <math.h>

void	ft_cleanup(t_params *prms)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (prms->map[ix])
	{
		while (prms->map[ix][iy])
		{
			if (prms->map[ix][iy] == 'T')
				prms->map[ix][iy] = '0';
			if (prms->map[ix][iy] == '0')
				prms->map[ix][iy] = ' ';
			iy++;
		}
		ix++;
		iy = 0;
	}
}

void	ft_outer_walls(t_params *prms)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (prms->map[ix])
	{
		while (prms->map[ix][iy])
		{
			if (ix == 0 || iy == 0 || prms->map[ix + 1] == NULL
				|| prms->map[ix][iy + 1] == 0)
				prms->map[ix][iy] = '1';
			iy++;
		}
	ix++;
	iy = 0;
	}
}

void	ft_fill_map(t_params *prms)
{
	printf("%d\n", prms->size);
	ft_outer_walls(prms);
	if (prms->size <= 20)
		ft_rooms(prms, 1 + rand() % 1);
	else if (prms->size < 30)
		ft_rooms(prms, 2 + rand() % 2);
	else
		ft_rooms(prms, 1 + rand() % ft_min(prms->size / 5, 10));
	ft_cleanup(prms);
}
