/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:41:37 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:18:30 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	digitcount(int n)
{
	int	i;

	i = 0;
	if (n >= 0)
	{
		while (n != 0 || i == 0)
		{
			n = n / 10;
			i++;
		}
		return (i);
	}
	else if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		while (n != 0)
		{
			n = n / 10;
			i++;
		}
		i++;
		return (i);
	}
	return (11);
}

static char	*swap(char	*d)
{
	int		i;
	int		ir;
	char	tmp;

	i = 0;
	if (d[0] == '-')
		i++;
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

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc((digitcount(n) + 1) * sizeof(char));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[i] = '-';
		i++;
	}
	while (n != 0 || i == 0)
	{
		ret[i] = ft_abs((n % 10)) + 48;
		n = n / 10;
		i++;
	}
	ret[i] = '\0';
	return (swap(ret));
}
