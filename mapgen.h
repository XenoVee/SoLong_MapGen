/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 19:57:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/05 16:38:24 by rmaes         ########   odam.nl         */
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
	unsigned int	size;
	char			**map;
}				t_params;

char			*ft_map_malloc(unsigned long count, unsigned long size);
char			**ft_create_map(t_params *prms);
void			*free_map(t_params *prms, int malloced);
void			ft_print_map(t_params *prms);
void			ft_fill_map(t_params *prms);
unsigned long	ft_seedconv(char *str);
void			ft_parse_args(int argc, char **argv, t_params *prms);
void			ft_setup_params(int argc, char **argv, t_params *prms);
void			ft_rooms(t_params *prms, unsigned int nrooms);
void			ft_generate_room(unsigned int room[2][2], t_params *prms);
void			ft_draw_room(unsigned int room[2][2], t_params *prms);
int				ft_minimum(int n, int c);
void			ft_draw_door(t_params *prms, unsigned int room[2][2]);
int				chckx(t_params *prms, unsigned int ix,
					unsigned int iy, int mod);
int				chcky(t_params *prms, unsigned int ix,
					unsigned int iy, int mod);
int				check_space(unsigned int room[2][2], t_params *prms);
#endif
