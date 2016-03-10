/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:07:30 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/21 17:07:38 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

# define ZOOM 14
# define LENGTH 900
# define ALTITUDE 1

typedef struct			s_point
{
	int					x;
	int					y;
	float				a;
	float				b;
	int					alt;
	int					color;
	struct s_point		*next;
	struct s_point		*prev;
}						t_point;

typedef struct			s_max_xy
{
	int					x;
	int					y;
	float				ajout_x;
	float				ajout_y;
}						t_max_xy;

int				main(int ac, char **av);

#endif
