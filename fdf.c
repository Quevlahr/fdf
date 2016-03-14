/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:43:47 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/20 16:45:57 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_menu(t_tool *tool)
{
	char		*str1;
	char		*str2;
	char		*str3;

	str1 = ft_strnew(8);
	ft_strcpy(str1, "Bonjour");
	str2 = ft_strnew(35);
	ft_strcpy(str2, "Bienvenue sur le projet Fil de Fer");
	str3 = ft_strnew(87);
	ft_strcpy(str3, "Appuyez sur espace pour commencer et sur m pour le menu");
	
	ft_putnbrdl(ft_strlen(str2) / 2);

	mlx_string_put(tool->mlx, tool->win, LENGTH / 2 - (ft_strlen(str1) / 2) * 10, 0, 0xffffff, str1);
	mlx_string_put(tool->mlx, tool->win, LENGTH / 2 - (ft_strlen(str2) / 2) * 10, 20, 0xffffff, str2);
	mlx_string_put(tool->mlx, tool->win, LENGTH / 2 - (ft_strlen(str3) / 2) * 10, 40, 0xffffff, str3);
}

int				ft_putkey(int keycode, t_tool *tool)
{
	ft_putstr("key event ");
	ft_putnbrdl(keycode);
	if (keycode == 53) // echap
	{
		mlx_destroy_window(tool->mlx, tool->win);
		exit(0);
	}
	else if (keycode == 49) // espace
	{
		mlx_clear_window(tool->mlx, tool->win);
		ft_putendl("4");
		ft_trace(tool);
	}
	else if (keycode == 46) // m
	{
		mlx_clear_window(tool->mlx, tool->win);
		ft_putendl("5");
		ft_menu(tool);
	}
	else if (keycode == 69) // plus
	{
		tool->zoom += 1;
		ft_trace(tool);
	}
	else if (keycode == 46) // moins
	{
		tool->zoom -= 1;
		ft_trace(tool);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_point		*pnt;
	t_help		*tmp;
	t_tool		*tool;
	void		*mlx;
	void		*win;

	tmp = NULL;
	tool = NULL;
	ft_help1(&tmp);
	pnt = ft_read_file(NULL, tmp, av[1], NULL);
	if ((mlx = mlx_init()) == NULL)
		ft_error();
	win = mlx_new_window(mlx, LENGTH, LENGTH, "Test_point");
	ft_help2(pnt, &tool, mlx, win);
	ft_atthebeginning(&pnt);
	tool->p = pnt;
	ft_menu(tool);
	// ft_trace(pnt, tool);
	mlx_key_hook(tool->win, ft_putkey, &tool);
	mlx_loop(tool->mlx);
	(void) ac;
	return (0);
}
