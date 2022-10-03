/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 18:04:32 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/03 17:40:00 by rmaes         ########   odam.nl         */
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

	ft_setup_params(argc, argv, &prms);
	prms.map = ft_create_map(&prms);
	if (prms.map == NULL)
		return (0);
	ft_fill_map(&prms);
	ft_print_map(&prms);
	free_map(&prms, prms.x);
}
