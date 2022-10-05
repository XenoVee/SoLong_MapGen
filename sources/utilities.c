/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 16:26:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/04 18:03:43 by rmaes         ########   odam.nl         */
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
