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
#include <fcntl.h> // pour open
# include <stdlib.h>
# include <math.h>

# define LENGTH 900

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

typedef struct			s_help
{
	int					x;
	int					y;
	int					alt;
	int					color;
}						t_help;

typedef struct			s_tool
{
	int					x;
	int					y;
	int					zoom;
	float				ajout_x;
	float				ajout_y;
	float				height;
	void				*mlx;
	void				*win;
}						t_tool;

int					main(int ac, char **av);
t_point				*ft_read_file(t_point *pt1, t_help *tmp, char *file, char *str);
void				ft_error(void);
void				ft_help1(t_help **tmp);
void				ft_help2(t_tool **tool, void *mlx, void *win);


#endif
