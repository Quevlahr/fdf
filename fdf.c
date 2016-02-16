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
#include <fcntl.h> // pour open
#include <stdio.h> // printf

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
	tmp->color = 0;
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

int				ft_putkey(int keycode, void *param)
{
	ft_putstr("key event ");
	ft_putnbrdl(keycode);
	(void) param;
	return (1);
}

int				ft_trace(int pt1)

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	int		x = 1;
	int		y = 1;
	int			alt;
	t_point		*pt1;
	char		*str = NULL;
	int			fd = 0;
	float		a, b;
	t_max_xy	*max;

	max = (t_max_xy*)malloc(sizeof(t_max_xy));
	max->x = 0;
	max->y = 0;
	a = b = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &str) > 0)
		{
			ft_putendl(str);
			x = 0;
			while (*str != '\0')
			{
				alt = ft_atoi(str);
				while (ft_isdigit(*str) && *str)
					str++;
				while (*str == ' ' && *str)
					str++;
				ft_createpoint(&pt1, x, y, alt);
				// ft_createpoint(&pt1, x * ZOOM + 450, y * ZOOM, alt);
				x++;
			}
			y++;
		}
		while (pt1->prev)
		{
			if (max->y < pt1->y)
				max->y = pt1->y;
			if (max->x < pt1->x)
				max->x = pt1->x;
			pt1 = pt1->prev;
		}

		max->ajout_x = LENGTH / 2 - max->x * ZOOM / 2;
		max->ajout_y = LENGTH / 2 - max->y * ZOOM / 2;

		ft_putpoints(pt1);
		close(fd);
		mlx = mlx_init();
		win = mlx_new_window(mlx, LENGTH, LENGTH, "Test_point");
		while (pt1)
		{
			ft_trace
			ft_calc_iso1(pt1, &a, &b);
			a = pt1->x * ZOOM + max->ajout_x;
			b = pt1->y * ZOOM + max->ajout_y;

			// iso 
			// a -= pt1->y * ZOOM;
			// b += pt1->x * ZOOM * 0.5;
			// b -= pt1->y * ZOOM * 0.5;

			// iso 
			a += pt1->y * ZOOM;
			b -= pt1->x * ZOOM * 0.5; // sin(30)
			b -= pt1->y * ZOOM * 0.5;

			// if (pt1->x == 0)
			// {
			// 	max->x--;
			// 	max->y--;
			// }
			// a = pt1->x * ZOOM * cos(30 * PI /180) + max->ajout_x;
			// b = pt1->y * ZOOM * sin(30 * PI /180) + max->ajout_y;
			// a += pt1->y * ZOOM;//* cos(30 * PI / 180);
			// b -= pt1->x * ZOOM * sin(30 * PI /180);//* sin(30 * PI /180); //part de 0 pour ajouter plus et remonter plus

			// if (pt1->x == 0)
			// 		max->x--;
			// a = (pt1->x + 1) * ZOOM * cos(30 * PI /180) + (ZOOM * cos(30 * PI / 180) * max->x);
			// b = (pt1->y + 1) * ZOOM * sin(30 * PI / 180) + (ZOOM * sin(30 * PI / 180) * pt1->x;

			// quasi parallele
			// a = (pt1->x + 1) * (ZOOM - (ZOOM - (ZOOM * 0.82)));
			// b = ((pt1->y + 1) * ZOOM) + (ZOOM * 0.48 * pt1->x);

			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
			pt1 = pt1->next;

			// x = pt1->x;
			// y = pt1->y;
			// if (x > pt1->next->x)
			// {
			// 	while (x > pt1->next->x)
			// 	{
			// 		mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			// 		x--;
			// 	}
			// }
			// else
			// {
			// 	while (x < pt1->next->x)
			// 	{
			// 		mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			// 		x++;
			// 	}
			// }
			// if (y > pt1->next->y)
			// {
			// 	while (y > pt1->next->y)
			// 	{
			// 		mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			// 		y--;
			// 	}	
			// }
			// else
			// {
			// 	while (y < pt1->next->y)
			// 	{
			// 		mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			// 		y++;
			// 	}
			// }
			// pt1 = pt1->next;
			// x = pt1->x;
			// y = pt1->y;
			// a = (pt1->next->y - pt1->y) / (pt1->next->x - pt1->x);
			// b = pt1->y - a * pt1->x;
			// if (x < pt1->next->x)
			// {
			// 	while (x < pt1->next->x)
			// 	{
			// 		y = (int) (0.82 * x + b);
			// 		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF); //blanc
			// 		x++;
			// 	}
			// }
			// else
			// {
			// 	while (x > pt1->next->x)
			// 	{
			// 		y = (int) (0.82 * x + b);
			// 		mlx_pixel_put(mlx, win, x, y, 0x0000FFFF); //blanc
			// 		x--;
			// 	}	
			// }
			// pt1 = pt1->next;
		}
		// ft_trace();
		mlx_key_hook(win, ft_putkey, 0);
		mlx_loop(mlx);
	}
	return (1);
}
