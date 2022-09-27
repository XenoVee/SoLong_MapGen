/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 16:26:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/22 22:23:34 by rmaes         ########   odam.nl         */
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

// make sure n is at least c - return largest
int	ft_max(int n, int c)
{
	if (n < c)
		return (c);
	return (n);
}

// make sure n is at most c - return smallest
int	ft_min(int n, int c)
{
	if (n > c)
		return (c);
	return (n);
}
