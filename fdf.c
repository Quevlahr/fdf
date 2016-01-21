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

int				ft_trace(void)
{
	ft_putstr("COUCOU");
	return (1);
}

int				main(void)
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Martin");
	x = 100;
	y = 100;
	while (x < 226)
	{
		y = 100;
		mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
		while (y < 226)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			if (x % 20 == 0)
				y++;
			else
				y += 25;
		}
		x++;
	}
	ft_trace();
	mlx_loop(mlx);
	return (1);
}
