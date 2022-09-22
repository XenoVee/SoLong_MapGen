/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 16:26:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 16:04:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	*free_map(char **map, int malloced)
{
	int	i;

	i = 0;
	while (i < malloced)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
