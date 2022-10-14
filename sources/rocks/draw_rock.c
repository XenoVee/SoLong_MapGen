/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_rock.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:47:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/14 16:48:31 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

void	draw_rock(t_params *prms, unsigned int rock[2])
{
	int	ix;
	int	iy;

	ix = -1;
	iy = -1;
	prms->map[rock[0]][rock[1]] = '1';
	while (ix <= 1)
	{
		while (iy <= 1)
		{
			if ((ix == 0 || iy == 0) && rand() % 2 == 1)
				prms->map[rock[0] + ix][rock[1] + iy] = '1';
			iy++;
		}
		iy = 0;
		ix++;
	}
}
