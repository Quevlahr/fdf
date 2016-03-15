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
		ft_putendl("ICI?");
		mlx_clear_window(tool->mlx, tool->win);
		ft_putendl("LA?");
		(keycode == 49) ? ft_trace(*tool) : 0; // espace
		(keycode == 46) ? ft_menu(*tool) : 0; // m
		(keycode == 69) ? tool->zoom += 1 : 0; // plus
		(keycode == 69) ? ft_trace(*tool) : 0; // plus
		(keycode == 78) ? tool->zoom -= 1 : 0; // plus
		(keycode == 78) ? ft_trace(*tool) : 0; // moins
		(keycode == 82) ? tool->zoom = 14 : 0; // plus
		(keycode == 82) ? ft_trace(*tool) : 0; // moins
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

void			ft_help3(t_point *pnt, t_tool *tool)
{
	if ((tool = (t_tool*)malloc(sizeof(t_tool))) == NULL)
		ft_error();
	(*tool).x = 0;
	(*tool).y = 0;
	(*tool).zoom = 14;
	(*tool).height = 1.5;
	(*tool).ajout_x = 0;
	(*tool).ajout_y = 0;
	// (*tool)->mlx = mlx;
	// (*tool)->win = win;
	ft_attheend(&pnt);
	while (pnt->prev)
	{
		if ((*tool).y < pnt->y)
			(*tool).y = pnt->y;
		if ((*tool).x < pnt->x)
			(*tool).x = pnt->x;
		pnt = pnt->prev;
	}
}

int				main(int ac, char **av)
{
	t_point		*pnt;
	t_help		*help;
	t_tool		tool;
	// void		*mlx;
	// void		*win;

	help = NULL;
	ft_help1(&help);
	pnt = ft_read_file(NULL, help, av[1], NULL);
	ft_help3(pnt, &tool);
	ft_putendl("JOULI GANT");
	if ((tool.mlx = mlx_init()) == NULL)
		ft_error();
	
	ft_putendl("OUPA");
	if ((tool.win = mlx_new_window(tool.mlx, LENGTH, LENGTH, "Test_point")) == NULL)
		ft_error();
	// ft_help2(pnt, &tool, mlx, win);
	ft_atthebeginning(&pnt);
	tool.p = pnt;
	ft_menu(tool);
	// ft_trace(tool);
	mlx_key_hook(tool.win, ft_putkey, &tool);
	// mlx_loop_hook(tool->win, ft_putyolo, tool);
	mlx_loop(tool.mlx);
	(void) ac;
	return (0);
}
