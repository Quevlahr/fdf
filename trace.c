/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:06:28 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/14 15:06:30 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



// void			ft_calc_iso1(t_point **pnt, t_tool *tool)
// {
// 	ft_atthebeginning(pnt);
// 	while (*pnt)
// 	{
// 		(*pnt)->a = (*pnt)->x * tool->zoom + tool->ajout_x;
// 		(*pnt)->b = (*pnt)->y * tool->zoom + tool->ajout_y;

// 		(*pnt)->a += (*pnt)->y * tool->zoom;
// 		(*pnt)->b -= (*pnt)->x * tool->zoom * 0.5; // sin(30)
// 		(*pnt)->b -= (*pnt)->y * tool->zoom * 0.5;

// 		if ((*pnt)->alt != 0)
// 			(*pnt)->b -= (*pnt)->alt * tool->zoom * tool->height;
// 		*pnt = (*pnt)->next;
// 	}
// }

// void			ft_trace3(void *mlx, void *win, t_point *pt1, t_max_xy *max)
// {
// 	float		a;
// 	float		b;
// 	float		a_eq;
// 	float		b_eq;

// 	a_eq = (ft_found(pt1, max->x, 0) - pt1->b) / (ft_found(pt1, max->x, 1) - pt1->a);
// 	b_eq = pt1->b - a_eq * pt1->a;
// 	a = pt1->a;
// 	b = pt1->b;
// 	if (a < ft_found(pt1, max->x, 1))
// 		while (a < ft_found(pt1, max->x, 1))
// 		{
// 			b = (int) (a_eq * a + b_eq);
// 			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 			a++;
// 			if (b < (int) (a_eq * a + b_eq))
// 				while (b < (int) (a_eq * a + b_eq))
// 				{
// 					b++;
// 					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 				}
// 			else
// 				while (b > (int) (a_eq * a + b_eq))
// 				{
// 					b--;
// 					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 				}
// 		}
// }

// void			ft_trace2(void *mlx, void *win, t_point *pt1)
// {
// 	float		a;
// 	float		b;
// 	float		a_eq;
// 	float		b_eq;

// 	a_eq = (pt1->next->b - pt1->b) / (pt1->next->a - pt1->a);
// 	b_eq = pt1->b - a_eq * pt1->a;
// 	a = pt1->a;
// 	b = pt1->b;
// 	if (a < pt1->next->a)
// 		while (a < pt1->next->a)
// 		{
// 			b = (int) (a_eq * a + b_eq);
// 			mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 			a++;
// 			if (b < (int) (a_eq * a + b_eq))
// 				while (b < (int) (a_eq * a + b_eq) && b++)
// 					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 			else
// 				while (b > (int) (a_eq * a + b_eq) && b--)
// 					mlx_pixel_put(mlx, win, a, b, 0x00FFFFFF);
// 		}
// }

void				ft_trace(t_tool *tool)
{
	t_point			*pnt;

	ft_putendl("1");
	pnt = tool->p;
	ft_putendl("2");
	tool->ajout_x = LENGTH / 2 - tool->x * tool->zoom / 2;
	tool->ajout_y = LENGTH / 2 - tool->y * tool->zoom / 2;
	// ft_calc_iso1(&pnt, tool);
	ft_putendl("3");
	ft_atthebeginning(&pnt);
	while (pnt->next)
	{
		pnt->a = pnt->x * tool->zoom + tool->ajout_x;
		pnt->b = pnt->y * tool->zoom + tool->ajout_y;

		pnt->a += pnt->y * tool->zoom;
		pnt->b -= pnt->x * tool->zoom * 0.5; // sin(30)
		pnt->b -= pnt->y * tool->zoom * 0.5;
		pnt = pnt->next;
	}
	ft_atthebeginning(&pnt);
	while (pnt->next)
	{
		// ft_putnbrdl(tool->ajout_x);
		mlx_pixel_put(tool->mlx, tool->win, pnt->a, 
			pnt->b, 0xFFFFFF);
		pnt = pnt->next;
	}
	// while (pt1->next)
	// {
	// 	ft_calc_iso1(pt1, max);
	// 	pt1 = pt1->next;
	// }
	// ft_atthebeginning(&pt1);
	// while (pt1->next)
	// {
	// 	ft_trace2(mlx, win, pt1);
	// 	pt1 = pt1->next;
	// }
	// ft_atthebeginning(&pt1);
	// while (pt1->next)
	// {
	// 	ft_trace3(mlx, win, pt1, max);
	// 	pt1 = pt1->next;
	// }
	// // ft_after_next();
}