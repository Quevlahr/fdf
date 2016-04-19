/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:10:51 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/21 20:10:53 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_trace_vertical(t_point *p, t_env env, float a, float b)
{
	float		a_eq;
	float		b_eq;

	a_eq = (ft_found(p, env.x, 0) - p->b) / (ft_found(p, env.x, 1) - p->a);
	b_eq = p->b - a_eq * p->a;
	a = p->a;
	b = p->b;
	while (a < ft_found(p, env.x, 1) && (b = (int)(a_eq * a + b_eq)))
	{
		ft_put_pixel_v(p, env, a, b);
		a++;
		if (b < (int)(a_eq * a + b_eq))
			while (b < (int)(a_eq * a + b_eq))
			{
				b++;
				ft_put_pixel_v(p, env, a, b);
			}
		else
			while (b > (int)(a_eq * a + b_eq))
			{
				b--;
				ft_put_pixel_v(p, env, a, b);
			}
	}
}

static void		ft_trace_horizontal(t_point *pnt, t_env env, float a, float b)
{
	float		a_eq;
	float		b_eq;

	a_eq = (pnt->next->b - pnt->b) / (pnt->next->a - pnt->a);
	b_eq = pnt->b - a_eq * pnt->a;
	a = pnt->a;
	b = pnt->b;
	while (a < pnt->next->a)
	{
		b = (int)(a_eq * a + b_eq);
		ft_put_pixel_h(pnt, env, a, b);
		a++;
		if (b < (int)(a_eq * a + b_eq))
			while (b < (int)(a_eq * a + b_eq) && b++)
				ft_put_pixel_h(pnt, env, a, b);
		else
			while (b > (int)(a_eq * a + b_eq) && b--)
				ft_put_pixel_h(pnt, env, a, b);
	}
}

static void		ft_calc_iso1(t_point *pnt, t_env env)
{
	ft_atthebeginning(&pnt);
	while (pnt)
	{
		pnt->a = pnt->x * env.zoom + env.ajout_x;
		pnt->b = pnt->y * env.zoom + env.ajout_y;
		pnt->a += pnt->y * env.zoom;
		pnt->b -= pnt->x * env.zoom * 0.5;
		pnt->b -= pnt->y * env.zoom * 0.5;
		if (pnt->alt != 0)
			pnt->b -= pnt->alt * env.zoom * env.height;
		pnt = pnt->next;
	}
}

void			ft_trace1(t_env env, t_point *pnt)
{
	pnt = env.pnt;
	ft_calc_iso1(pnt, env);
	ft_atthebeginning(&pnt);
	while (pnt->next)
	{
		ft_trace_horizontal(pnt, env, 0, 0);
		pnt = pnt->next;
	}
	ft_atthebeginning(&pnt);
	while (pnt->next)
	{
		ft_trace_vertical(pnt, env, 0, 0);
		pnt = pnt->next;
	}
}
