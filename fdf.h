/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:18:22 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/15 21:18:25 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>

# define LENGTH 1000
# define WHITE 16777215

typedef struct			s_point
{
	int					x;
	int					y;
	float				a;
	float				b;
	int					alt;
	long				color;
	struct s_point		*next;
	struct s_point		*prev;
}						t_point;

typedef struct			s_env
{
	int					x;
	int					y;
	int					zoom;
	int					len;
	int					len_x;
	int					len_y;
	float				ajout_x;
	float				ajout_y;
	float				height;
	struct s_point		*pnt;
	void				*mlx;
	void				*win;
}						t_env;

typedef struct			s_help
{
	int					x;
	int					y;
	int					alt;
	long				color;
}						t_help;

void					ft_error(t_env *env);
void					ft_atthebeginning(t_point **pnt);
void					ft_attheend(t_point **pnt);
void					ft_putpoints(t_point *pnt);
float					ft_found(t_point *pnt, int i, int boolean);
void					ft_read(int fd, t_point **pnt, char *str);
void					ft_menu(t_env env);
void					ft_menu1(t_env env);
void					ft_trace1(t_env env, t_point *pnt);
int						ft_keyuse(int key, t_env *env);
int						ft_verif(char *str, int bo);
void					ft_verif_taille(t_point *pnt, t_env *env, int ln,
										int bo);
void					ft_put_pixel_v(t_point *pnt, t_env env, float a,
										float b);
void					ft_put_pixel_h(t_point *pnt, t_env env, float a,
										float b);

#endif
