/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 16:26:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/03 17:38:29 by rmaes         ########   odam.nl         */
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
