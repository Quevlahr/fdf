/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:12:13 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/15 21:12:15 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
