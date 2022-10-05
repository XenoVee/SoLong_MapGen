/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btw.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 18:03:51 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/04 18:04:01 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// make sure n is between d and i
int	ft_btw(int n, int d, int i)
{
	return (ft_min(ft_max(n, i), d));
}
