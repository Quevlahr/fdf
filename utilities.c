/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:26:55 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/03 19:27:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_help1(t_help **tmp)
{
	*tmp = (t_help*)malloc(sizeof(t_help));
	(*tmp)->x = 0;
	(*tmp)->y = 0;
	(*tmp)->alt = 0;
	(*tmp)->color = 0;
}

void	ft_help2(t_tool **tool, void *mlx, void *win)
{
	(*tool)->x = 0;
	(*tool)->y = 0;
	(*tool)->zoom = 14;
	(*tool)->height = 1.5;
	(*tool)->ajout_x = LENGTH / 2 - (*tool)->zoom;
	(*tool)->ajout_y = LENGTH / 2 - (*tool)->zoom;
	(*tool)->mlx = mlx;
	(*tool)->win = win;
}

// static void		ft_putpoints(t_point *pnt)
// {
// 	while (pnt->prev)
// 		pnt = pnt->prev;
// 	while (pnt)
// 	{
// 		ft_putnbr(pnt->x);
// 		ft_putstr(" - ");
// 		ft_putnbr(pnt->y);
// 		ft_putstr(" - ");
// 		ft_putnbr(pnt->alt);
// 		ft_putstr(" - ");
// 		ft_putnbr(pnt->color);
// 		ft_putstr(";\n");
// 		pnt = pnt->next;
// 	}
// }
