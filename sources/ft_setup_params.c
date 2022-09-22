/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup_params.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 16:03:51 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 21:26:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"
#include <time.h>

void	ft_parse_args(int argc, char **argv, t_params *params)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "-s", 2))
			params->seed = ft_seedconv(argv[i + 1]);
		if (!ft_strncmp(argv[i], "-y", 2))
			params->y = ft_atoi(argv[i + 1]);
		if (!ft_strncmp(argv[i], "-x", 2))
			params->x = ft_atoi(argv[i + 1]);
		i += 2;
	}
}

void	ft_setup_params(int argc, char **argv, t_params *params)
{
	params->y = 0;
	params->x = 0;
	params->seed = 0;
	if (argc == 2)
		params->seed = ft_seedconv(argv[1]);
	if (argc > 2)
		ft_parse_args(argc, argv, params);
	if (params->seed == 0)
		params->seed = time(NULL) * getpid();
	srand(params->seed);
	if (params->x == 0)
		params->x = rand() % 20 + 10;
	if (params->y == 0)
		params->y = rand() % 20 + 10;
	return ;
}
