/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 20:58:23 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	ft_print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x][y] != 0)
	{
		while (map[x])
		{
			if (x > 0)
				write(1, " ", 1);
			write(1, &map[x][y], 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}
