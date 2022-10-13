/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoul.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 16:41:27 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/13 18:55:30 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	ulonglen(void)
{
	unsigned long	ul;
	int				len;

	ul = ULONG_MAX;
	len = 0;
	while (ul)
	{
		ul /= 10;
		len++;
	}
	return (len);
}

static int	atoul_strcmp(const char	*str1, char *str2)
{
	int	i;
	int	l;

	l = ulonglen();
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i] && i <= l)
		i++;
	return (str2[i] - str1[i]);
}

static int	max_check(const char *str)
{
	int		i;
	int		ret;
	char	*s;
	int		l;

	i = 0;
	ret = 0;
	l = ulonglen();
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (i < l)
		return (0);
	else if (i == l)
	{
		s = ft_ultoa(ULONG_MAX);
		ret = atoul_strcmp(str, s);
		free (s);
	}
	else if (i > l)
		return (-1);
	return (ret);
}

unsigned long	ft_atoul(const char *str)
{
	unsigned long	num;
	int				i;

	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	if (max_check(&str[i]) < 0)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		str++;
	}
	return (num);
}
