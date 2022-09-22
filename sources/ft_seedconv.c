/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_seedconv.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 19:15:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 15:56:48 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

unsigned long	ft_seedconv(char	*str)
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
