/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 16:26:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/14 17:01:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	*free_map(t_params *prms, int malloced)
{
	int	i;

	i = 0;
	while (i < malloced)
	{
		free(prms->map[i]);
		i++;
	}
	free(prms->map);
	return (NULL);
}

void	ft_finalize(t_params *prms, char c, char f)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (prms->map[ix])
	{
		while (prms->map[ix][iy])
		{
			if (prms->map[ix][iy] == c)
				prms->map[ix][iy] = f;
			iy++;
		}
		ix++;
		iy = 0;
	}
}
