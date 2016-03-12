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

int				ft_putkey(int keycode, void *param)
{
	ft_putstr("key event ");
	ft_putnbrdl(keycode);
	(void) param;
	if (keycode == 53)
		exit(0);
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
	mlx = mlx_init();
	win = mlx_new_window(mlx, LENGTH, LENGTH, "Test_point");
	ft_help2(&tool, mlx, win);
	mlx_key_hook(win, ft_putkey, 0);
	mlx_loop(mlx);
	(void) ac;
	return (0);
}
