/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_seedconv.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 19:15:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/12 19:55:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

t_seed	ft_seedconv(char	*str)
{
	unsigned long	ret;
	int				i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret += str[i];
		i++;
	}
	return (ret);
}
