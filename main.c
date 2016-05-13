/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:12:13 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/13 21:46:58 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_raz(t_env *env)
{
	env->zoom = 14;
	env->ajout_x = env->len_x / 2 - (env->x * env->zoom);
	env->ajout_y = env->len_y / 2;
	env->height = 1.5;
}

static void		ft_dezoom(t_env *env)
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

static void		ft_help_hook(int key, t_env *env)
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

static int		key_hook(int key, t_env *env)
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
		ft_help_hook(key, env);
		ft_trace1(*env, NULL);
	}
	return (1);
}

static void		ft_initenv(t_env *env)
{
	env->zoom = 14;
	env->height = 1.5;
	env->len_x = env->x * env->zoom * 3;
	env->len_y = env->y * env->zoom * 1.8;
	(env->len_x > 2500) ? env->zoom = 2 : 0;
	(env->len_y > 1350) ? env->zoom = 2 : 0;
	(env->len_x < 600) ? env->len_x = 600 : 0;
	(env->len_x > 2500) ? env->len_x = 2500 : 0;
	(env->len_y < 500) ? env->len_y = 500 : 0;
	(env->len_y > 1350) ? env->len_y = 1350 : 0;
	env->len = env->len_x + env->len_y;
	env->ajout_x = env->len_x / 2 - (env->x * env->zoom);
	env->ajout_y = env->len_y / 2;
}

static void		launcher(t_point *pnt, t_env env)
{
	ft_atthebeginning(&pnt);
	env.pnt = pnt;
	if ((env.mlx = mlx_init()) == NULL)
		ft_error(NULL);
	if ((env.win = mlx_new_window(env.mlx, env.len_x, env.len_y
		, "Fdf quroulon")) == NULL)
		ft_error(NULL);
	ft_menu(env);
	mlx_key_hook(env.win, ft_keyuse, &env);
	mlx_hook(env.win, 2, (1L << 01), key_hook, &env);
	mlx_loop(env.mlx);
}

int				main(int ac, char **av)
{
	int			fd;
	t_point		*pnt;
	t_env		env;
	char		*str;

	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd > 0)
	{
		ft_read(fd, &pnt, str);
		ft_strdel(&str);
		ft_verif_taille(pnt, &env, 0, 0);
		ft_initenv(&env);
		launcher(pnt, env);
	}
	else
		ft_error(NULL);
	close(fd);
	return (0);
}
