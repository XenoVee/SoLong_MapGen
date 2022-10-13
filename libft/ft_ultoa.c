/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 16:41:37 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/13 17:39:32 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	digitcount(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0 || i == 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*swap(char	*d)
{
	int		i;
	int		ir;
	char	tmp;

	i = 0;
	ir = ft_strlen(d) - 1;
	while (i <= ir)
	{
		tmp = d[i];
		d[i] = d[ir];
		d[ir] = tmp;
		i++;
		ir--;
	}
	return (d);
}

char	*ft_ultoa(unsigned long n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc((digitcount(n) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (n != 0 || i == 0)
	{
		ret[i] = ft_abs((n % 10)) + 48;
		n = n / 10;
		i++;
	}
	ret[i] = '\0';
	return (swap(ret));
}
