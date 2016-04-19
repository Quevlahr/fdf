/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:00:53 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/16 14:00:54 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*ft_pntnew(t_help tmp)
{
	t_point		*new_pnt;

	if (!(new_pnt = (t_point*)malloc(sizeof(t_point))))
		ft_error(NULL);
	new_pnt->x = tmp.x;
	new_pnt->y = tmp.y;
	new_pnt->a = 0;
	new_pnt->b = 0;
	new_pnt->alt = tmp.alt;
	new_pnt->color = tmp.color;
	new_pnt->next = NULL;
	new_pnt->prev = NULL;
	return (new_pnt);
}

static void		ft_pntpush(t_point **pnt, t_help tmp)
{
	t_point		*tmp_pnt;
	t_point		*prev_pnt;

	tmp_pnt = *pnt;
	if (tmp_pnt)
	{
		while (tmp_pnt->next)
			tmp_pnt = tmp_pnt->next;
		prev_pnt = tmp_pnt;
		tmp_pnt->next = ft_pntnew(tmp);
		tmp_pnt = tmp_pnt->next;
		tmp_pnt->prev = prev_pnt;
	}
	else
		*pnt = ft_pntnew(tmp);
}

static int		ft_help_read(char *str, t_help *tmp)
{
	int			j;

	j = 0;
	while (str[j] && (str[j] == ' ' || str[j] == '\t'))
		j++;
	tmp->alt = ft_atoi(str + j);
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '-'))
		j++;
	if (str[j] == ',')
	{
		j += 3;
		tmp->color = ft_atoihexa(str + j);
		while (ft_ishexa(str[j]) == 1)
			j++;
	}
	return (j);
}

void			ft_read(int fd, t_point **pnt, char *str)
{
	t_help		tmp;
	int			i;

	tmp.y = 0;
	*pnt = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		i = 0;
		if (ft_verif(str, 0) == 0)
			ft_error(NULL);
		tmp.x = 0;
		tmp.alt = 0;
		while (str[i])
		{
			tmp.color = WHITE;
			i += ft_help_read(str + i, &tmp);
			ft_pntpush(pnt, tmp);
			tmp.x++;
			i++;
		}
		tmp.y++;
	}
	if (*pnt == NULL)
		ft_error(NULL);
}
