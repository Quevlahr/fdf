/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:18:48 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/23 16:18:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_raz(t_env *env)
{
	env->zoom = 14;
	env->ajout_x = env->len_x / 2 - (env->x * env->zoom);
	env->ajout_y = env->len_y / 2;
	env->height = 1.5;
}

void			ft_dezoom(t_env *env)
{
	char		*str;

	str = ft_strnew(31);
	if (env->zoom == 1)
	{
		ft_strcpy(str, "We can't zoom out anymore! LAWL");
		mlx_string_put(env->mlx, env->win,
			env->len_x / 2 - (ft_strlen(str) / 2) * 10, 0, 0xffffff, str);
	}
	else
		env->zoom -= 1;
}

static void		ft_help_keyuse(int key, t_env *env)
{
	(key == 69) ? env->zoom += 1 : 0;
	(key == 78) ? ft_dezoom(env) : 0;
	(key == 82) ? ft_raz(env) : 0;
	(key == 123) ? env->ajout_x -= 20 : 0;
	(key == 124) ? env->ajout_x += 20 : 0;
	(key == 125) ? env->ajout_y += 20 : 0;
	(key == 126) ? env->ajout_y -= 20 : 0;
	(key == 27) ? env->height -= 0.1 : 0;
	(key == 24) ? env->height += 0.1 : 0;
}

int				ft_keyuse(int key, t_env *env)
{
	if (key == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	else if (key == 46)
	{
		mlx_clear_window(env->mlx, env->win);
		(key == 46) ? ft_menu1(*env) : 0;
	}
	else if (key == 69 || key == 78 || key == 82 || key == 123
		|| key == 124 || key == 125 || key == 126 || key == 49
		|| key == 27 || key == 24)
	{
		mlx_clear_window(env->mlx, env->win);
		ft_help_keyuse(key, env);
		ft_trace1(*env, NULL);
	}
	return (1);
}
