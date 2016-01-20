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

#include "mlx.h"

int				main(void)
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	// int			col;
	// char		*str;
	// char		*str1;
	// char		*str2;
	// char		*str3;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "truc");
	x = 100;
	while (x < 250)
	{
		y = 100;
		// str = "0x00";
		// str1 = ft_itoa(x);
		// str2 = ft_itoa(x);
		// str3 = ft_itoa(y);
		// col = ft_atoi()
		while (y < 320)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (1);
}
