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

void			ft_putpoints(t_point *pt)
{
	while (pt)
	{
		ft_putnbr(pt->x);
		ft_putstr(" - ");
		ft_putnbr(pt->y);
		ft_putstr(" - ");
		ft_putnbr(pt->alt);
		ft_putstr(";\n");
		pt = pt->next;
	}
}

void			ft_createpoint(t_point **pt, int x, int y, int alt)
{
	t_point		*tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = x;
	tmp->y = y;
	tmp->alt = alt;
	tmp->next = NULL;
	if (*pt == NULL)
	{
		tmp->prev = NULL;
		*pt = tmp;
	}
	else
	{
		while ((*pt)->next != NULL)
			*pt = (*pt)->next;
		tmp->prev = *pt;
		(*pt)->next = tmp;
	}
}

int				ft_trace(void)
{
	ft_putstr("COUCOU");
	return (1);
}

int				main(void)
{
	// void		*mlx;
	// void		*win;
	int			x;
	int			y;
	t_point		*pt1;

	pt1 = (t_point*)malloc(sizeof(t_point));
	pt1 = NULL;
	ft_createpoint(&pt1, 0, 0, 1);
	ft_putpoints(pt1);
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "Martin");
	x = 100;
	y = 100;
	while (x < 226)
	{
		y = 100;
		// mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
		while (y < 226)
		{
			// mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			if (x % 20 == 0)
				y++;
			else
				y += 25;
		}
		x++;
	}
	// ft_trace();
	// mlx_loop(mlx);
	return (1);
}
