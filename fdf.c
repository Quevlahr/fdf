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

void			ft_putpoints(t_point *pt1)
{
	while (pt1)
	{
		ft_putnbr(pt1->a);
		ft_putstr(" - ");
		ft_putnbr(pt1->b);
		ft_putstr(" - ");
		ft_putnbr(pt1->alt);
		ft_putstr(";\n");
		pt1 = pt1->next;
	}
}

void			ft_atthebeginning(t_point **pt1)
{
	while ((*pt1)->prev != NULL)
		*pt1 = (*pt1)->prev;
}

void			ft_createpoint(t_point **pt, int x, int y, int alt)
{
	t_point		*tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = x;
	tmp->y = y;
	tmp->a = 0;
	tmp->b = 0;
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

t_point			*ft_read_file(t_point *pt1, char *file, char *str)
{
	int			x;
	int			y;
	int			alt;
	int			fd;

	y = 0;
	fd = open(file, O_RDONLY);
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
			x++;
		}
		y++;
	}
	close(fd);
	return (pt1);
}

int				ft_putkey(int keycode, void *param)
{
	ft_putstr("key event ");
	ft_putnbrdl(keycode);
	(void) param;
	return (1);
}

void			ft_calc_iso1(t_point *pt1, t_max_xy *max)
{
	pt1->a = pt1->x * ZOOM + max->ajout_x;
	pt1->b = pt1->y * ZOOM + max->ajout_y;

	pt1->a += pt1->y * ZOOM;
	pt1->b -= pt1->x * ZOOM * 0.5; // sin(30)
	pt1->b -= pt1->y * ZOOM * 0.5;

	if (pt1->alt != 0)
		pt1->b -= pt1->alt * ZOOM * 1.25;
}

float			ft_found(t_point *pt1, int i, int boolean)
{
	int			j;

	j = 0;
	while (j < i + 1 && pt1->next)
	{
		pt1 = pt1->next;
		j++;
	}
	if (pt1->next == NULL)
		return (0);
	if (boolean == 1)
		return (pt1->a);
	else
		return (pt1->b);
}

int				ft_trace(void *mlx, void *win, t_point *pt1, t_max_xy *max)
{
	float		a_eq;
	float		b_eq;

	while (pt1->next)
	{
		ft_calc_iso1(pt1, max);
		pt1 = pt1->next;
	}
	ft_putpoints(pt1);
	ft_atthebeginning(&pt1);
	ft_putpoints(pt1);
	while (pt1->next)
	{
		// a_eq = (pt1->next->b - pt1->b) / (pt1->next->a - pt1->a);
		// b_eq = pt1->b - a_eq * pt1->a;
		// if (pt1->a < pt1->next->a)
		// {
		// 	while (pt1->a < pt1->next->a)
		// 	{
		// 		pt1->b = (int) (a_eq * pt1->a + b_eq);
		// 		mlx_pixel_put(mlx, win, pt1->a, pt1->b, 0x00FFFFFF); //blanc
		// 		pt1->a += 1;
		// 	}
		// }

		a_eq = (ft_found(pt1, max->x, 0) - pt1->b) / (ft_found(pt1, max->x, 1) - pt1->a);
		b_eq = pt1->b - a_eq * pt1->a;
		if (pt1->a < ft_found(pt1, max->x, 1))
		{
			while (pt1->a < ft_found(pt1, max->x, 1))
			{
				pt1->b = (int) (a_eq * pt1->a + b_eq);
				mlx_pixel_put(mlx, win, pt1->a, pt1->b, 0x00FFFFFF); //blanc
				pt1->a += 1;
			}
		}
		// else
		// {
		// 	while (pt1->a > pt1->next->a)
		// 	{
		// 		pt1->b = (int) (a_eq * pt1->a + b_eq);
		// 		mlx_pixel_put(mlx, win, pt1->a, pt1->b, 0x0000FFFF); //blanc
		// 		pt1->a -= 1;
		// 	}	
		// }


		// mlx_pixel_put(mlx, win, pt1->a, pt1->b, 0x00FFFFFF);
		pt1 = pt1->next;
	}
	// ft_after_next();
	return (0);
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_point		*pt1;
	t_max_xy	*max;

	max = (t_max_xy*)malloc(sizeof(t_max_xy));
	max->x = 0;
	max->y = 0;
	if (ac == 2)
	{
		pt1 = ft_read_file(NULL, av[1], NULL);

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
		mlx = mlx_init();
		win = mlx_new_window(mlx, LENGTH, LENGTH, "Test_point");
		ft_trace(mlx, win, pt1, max);
		mlx_key_hook(win, ft_putkey, 0);
		mlx_loop(mlx);
	}
	return (1);
}
