/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:48:31 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/16 13:48:33 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_putpoints(t_point *pnt)
{
	while (pnt->prev)
		pnt = pnt->prev;
	while (pnt)
	{
		ft_putnbr(pnt->x);
		ft_putstr(" - ");
		ft_putnbr(pnt->y);
		ft_putstr(" - ");
		ft_putnbr(pnt->alt);
		ft_putstr(" - ");
		ft_putnbr(pnt->color);
		ft_putstr(";\n");
		pnt = pnt->next;
	}
}

void			ft_error(t_env *env)
{
	if (env == NULL)
	{
		ft_putendl("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putendl("Error");
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_FAILURE);
	}
}

void			ft_atthebeginning(t_point **pnt)
{
	while ((*pnt)->prev != NULL)
		*pnt = (*pnt)->prev;
}

void			ft_attheend(t_point **pnt)
{
	while ((*pnt)->next != NULL)
		*pnt = (*pnt)->next;
}

float			ft_found(t_point *pnt, int i, int boolean)
{
	int			j;
	int			tmp;

	j = 0;
	tmp = 0;
	if (pnt->next && pnt->y != pnt->next->y)
		tmp = 1;
	while (j < i + 1 && pnt->next)
	{
		pnt = pnt->next;
		j++;
	}
	if (pnt->next == NULL && tmp == 0)
		return (0);
	else if (boolean == 1)
		return (pnt->a);
	else if (boolean == 2)
		return (pnt->color);
	else
		return (pnt->b);
}
