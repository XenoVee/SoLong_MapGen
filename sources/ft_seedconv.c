/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_seedconv.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 19:15:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/13 16:06:10 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"
#include "libft/libft.h"

t_seed	ft_seedconv(char	*str)
{
	unsigned long	ret;
	int				i;

	ret = 0;
	i = 0;
	if (ft_is_atoi(str))
		return (ft_atoi(str));
	while (str[i])
	{
		ret += str[i];
		i++;
	}
	return (ret);
}
