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
	if (keycode == 53)
		exit(0);
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
		pt1->b -= pt1->alt * ZOOM * ALTITUDE;
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

// void			ft_helper()
// {
// 	b = (int) (a_eq * a + b_eq);
// 	mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 	a++;
// 	if (b < (int) (a_eq * a + b_eq))
// 		while (b < (int) (a_eq * a + b_eq))
// 		{
// 			b++;
// 			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 		}
// 	else
// 		while (b > (int) (a_eq * a + b_eq))
// 		{
// 			b--;
// 			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 		}
// }

void			ft_trace3(void *mlx, void *win, t_point *pt1, t_max_xy *max)
{
	float		a;
	float		b;
	float		a_eq;
	float		b_eq;

	a_eq = (ft_found(pt1, max->x, 0) - pt1->b) / (ft_found(pt1, max->x, 1) - pt1->a);
	b_eq = pt1->b - a_eq * pt1->a;
	a = pt1->a;
	b = pt1->b;
	if (a < ft_found(pt1, max->x, 1))
		while (a < ft_found(pt1, max->x, 1))
		{
			b = (int) (a_eq * a + b_eq);
			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
			a++;
			if (b < (int) (a_eq * a + b_eq))
				while (b < (int) (a_eq * a + b_eq))
				{
					b++;
					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
				}
			else
				while (b > (int) (a_eq * a + b_eq))
				{
					b--;
					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
				}
		}
}

void			ft_trace2(void *mlx, void *win, t_point *pt1)
{
	float		a;
	float		b;
	float		a_eq;
	float		b_eq;

	a_eq = (pt1->next->b - pt1->b) / (pt1->next->a - pt1->a);
	b_eq = pt1->b - a_eq * pt1->a;
	a = pt1->a;
	b = pt1->b;
	if (a < pt1->next->a)
		while (a < pt1->next->a)
		{
			b = (int) (a_eq * a + b_eq);
			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
			a++;
			if (b < (int) (a_eq * a + b_eq))
				while (b < (int) (a_eq * a + b_eq))
				{
					b++;
					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
				}
			else
				while (b > (int) (a_eq * a + b_eq))
				{
					b--;
					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
				}
		}
}

int				ft_trace(void *mlx, void *win, t_point *pt1, t_max_xy *max)
{
	while (pt1->next)
	{
		ft_calc_iso1(pt1, max);
		pt1 = pt1->next;
	}
	ft_atthebeginning(&pt1);
	while (pt1->next)
	{
		ft_trace2(mlx, win, pt1);
		pt1 = pt1->next;
	}
	ft_atthebeginning(&pt1);
	while (pt1->next)
	{
		ft_trace3(mlx, win, pt1, max);
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

		// max->ajout_x = LENGTH / 2 - max->x * ZOOM / 2;
		max->ajout_y = LENGTH - max->y * ZOOM / 2;

		mlx = mlx_init();
		win = mlx_new_window(mlx, LENGTH, LENGTH, "Test_point");
		ft_trace(mlx, win, pt1, max);
		mlx_key_hook(win, ft_putkey, 0);
		mlx_loop(mlx);
	}
	return (1);
}
