/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 18:04:32 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/22 18:05:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	leaks(void)
{
	write(1, "\n", 1);
	system("leaks -q mapgen");
}

int	main(int argc, char **argv)
{
	t_params	prms;
	char		**map;

	ft_setup_params(argc, argv, &prms);
	map = ft_create_map(&prms);
	if (map == NULL)
		return (0);
	ft_fill_map(map, &prms);
	ft_print_map(map);
	free_map(map, prms.x);
}
