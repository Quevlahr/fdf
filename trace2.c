/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:56:03 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/27 18:56:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_put_pixel_v(t_point *pnt, t_env env, float a, float b)
{
	if (ft_found(pnt, env.x, 2) != WHITE)
		mlx_pixel_put(env.mlx, env.win, a, b, ft_found(pnt, env.x, 2));
	else
		mlx_pixel_put(env.mlx, env.win, a, b, pnt->color);
}

void			ft_put_pixel_h(t_point *pnt, t_env env, float a, float b)
{
	if (pnt->next->color != WHITE)
		mlx_pixel_put(env.mlx, env.win, a, b, pnt->next->color);
	else
		mlx_pixel_put(env.mlx, env.win, a, b, pnt->color);
}
