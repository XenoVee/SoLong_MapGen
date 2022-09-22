/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 19:57:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/09/21 20:01:05 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPGEN_H
# define MAPGEN_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
// # include <stddef.h>

typedef struct s_params
{
	unsigned long	seed;
	unsigned int	x;
	unsigned int	y;
}				t_params;

char			*ft_map_malloc(unsigned long count, unsigned long size);
char			**ft_create_map(t_params *params);
void			*free_map(char **map, int malloced);
void			ft_print_map(char **map);
void			ft_fill_map(char **map);
unsigned long	ft_seedconv(char *str);
void			ft_parse_args(int argc, char **argv, t_params *params);
void			ft_setup_params(int argc, char **argv, t_params *params);

#endif
