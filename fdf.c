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

int				ft_putkey(int keycode, t_tool *tool)
{	
	// ft_putstr("key event ");
	// ft_putnbrdl(keycode);
	if (keycode == 53) // echap
	{
		mlx_destroy_window(tool->mlx, tool->win);
		exit(0);
	}
	else if (keycode == 49 || keycode == 46 || keycode == 69 || keycode == 78
		|| keycode == 82)
	{
		mlx_clear_window(tool->mlx, tool->win);
		(keycode == 49) ? ft_trace(tool) : 0; // espace
		(keycode == 46) ? ft_menu(tool) : 0; // m
		(keycode == 69) ? tool->zoom += 1 : 0; // plus
		(keycode == 69) ? ft_trace(tool) : 0; // plus
		(keycode == 78) ? tool->zoom -= 1 : 0; // plus
		(keycode == 78) ? ft_trace(tool) : 0; // moins
		(keycode == 82) ? tool->zoom = 14 : 0; // plus
		(keycode == 82) ? ft_trace(tool) : 0; // moins
		ft_trace(tool);
	}
	return (1);
}

// int				ft_putyolo(int keycode, t_tool *tool)
// {
// 	static int	i = 0;

// 	ft_putnbrdl(i);
// 	ft_putnbrdl(keycode);
// 	(void)tool;
// 	return (0);
// }

int				main(int ac, char **av)
{
	t_point		*pnt;
	t_help		*help;
	t_tool		*tool;
	void		*mlx;
	void		*win;

	help = NULL;
	tool = NULL;
	ft_putendl("1");
	ft_help1(&help);
	ft_putendl("2");
	pnt = ft_read_file(NULL, help, av[1], NULL);
	if ((mlx = mlx_init()) == NULL)
	{
		ft_putendl("mlx_init marche pas");
		ft_error();
	}
	if ((win = mlx_new_window(mlx, LENGTH, LENGTH, "Test_point")) == NULL)
	{
		ft_putendl("mlx_new_window marche pas");
		ft_error();
	}
	ft_putendl("3");
	ft_help2(pnt, &tool, mlx, win);
	ft_putendl("4");
	ft_atthebeginning(&pnt);
	tool->p = pnt;
	ft_putendl("5");
	ft_menu(tool);
	// ft_trace(tool);
	ft_putendl("6");
	mlx_key_hook(tool->win, ft_putkey, tool);
	// mlx_loop_hook(tool->win, ft_putyolo, tool);
	mlx_loop(tool->mlx);
	(void) ac;
	return (0);
}
