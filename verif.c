/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:34:36 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/26 18:34:48 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_help_verif(char **str)
{
	int			err;
	int			cpt;

	err = 0;
	cpt = 0;
	if (**str == '0')
		(*str)++;
	else
		err++;
	if (**str == 'X' || **str == 'x')
		(*str)++;
	else
		err++;
	while (ft_ishexa(**str) == 1)
	{
		cpt++;
		(*str)++;
	}
	if (cpt > 6)
		err++;
	if (err > 0)
		return (0);
	return (1);
}

int				ft_verif(char *str, int bo)
{
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (*str == '-')
			str++;
		while (*str && ft_isdigit(*str) == 1)
		{
			bo = 1;
			str++;
		}
		if (*str == ',' && bo == 1)
		{
			str++;
			if (ft_help_verif(&str) == 0)
				return (0);
		}
		if (*str && *str != ' ' && *str != '\t')
			return (0);
		str++;
		bo = 0;
	}
	return (1);
}

void			ft_verif_taille(t_point *pnt, t_env *env, int ln, int bo)
{
	env->x = 0;
	env->y = 0;
	ln = 0;
	bo = 0;
	ft_atthebeginning(&pnt);
	while (pnt->next)
	{
		if (pnt->next->x == 0 && bo == 0)
		{
			bo = 1;
			ln = pnt->x;
		}
		else if (pnt->next->x == 0 && bo == 1 && ln != pnt->x)
		{
			ft_putendl("AQUI 5");
			ft_error(NULL);
		}
		if (env->y < pnt->y)
			env->y = pnt->y;
		if (env->x < pnt->x)
			env->x = pnt->x;
		pnt = pnt->next;
	}
	// if (pnt->next == NULL && bo == 1 && ln != pnt->x)
	// {
	// 	ft_putendl("AQUI 6");
	// 	ft_error(NULL);
	// }
}
