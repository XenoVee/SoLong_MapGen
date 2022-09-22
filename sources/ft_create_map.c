/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_map.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:26:14 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 20:27:55 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

char	*ft_map_malloc(unsigned long count, unsigned long size)
{
	char	*ret;

	ret = ft_calloc(count, size);
	return (ret);
}

void	ft_setempty(char *mapx, int y)
{
	int	iy;

	iy = 0;
	while (iy < y)
	{
		mapx[iy] = '0';
		iy++;
	}
}

char	**ft_create_map(t_params *params)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc((params->x + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	while (i < params->x)
	{
		map[i] = ft_map_malloc(params->y + 1, sizeof(char));
		if (map == NULL)
		{
			free_map(map, i);
			return (NULL);
		}
		ft_setempty(map[i], params->y);
		i++;
	}
	map[i] = NULL;
	return (map);
}
