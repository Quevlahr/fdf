/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:17:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/03 19:17:28 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_putpoints(t_point *pnt)
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

static int			ft_ishexa(char *str)
{

		if (ft_isdigit(*str) == 1 || (*str <= 'f' && *str >= 'a') || (*str <= 'F' && *str >= 'A'))
			return (1);
		else
			return (0);

}

void				ft_createpoint(t_point **pt, t_help *help)
{
	t_point			*tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = help->x;
	tmp->y = help->y;
	tmp->a = 0;
	ft_putendl("here ?0");
	tmp->b = 0;
	tmp->alt = help->alt;
	tmp->color = help->color;
	tmp->next = NULL;
	if (*pt == NULL)
	{
		tmp->prev = NULL;
		*pt = tmp;
	}
	else
	{
		ft_putendl("here ?1");
		while ((*pt)->next != NULL)
			*pt = (*pt)->next;
		ft_putendl("here ?2");
		tmp->prev = *pt;
		(*pt)->next = tmp;
		ft_putendl("here ?3");
	}
}

long				ft_atoihexa(char *str)
{
	int				i;
	long				res;

	i = 0;
	res = 0;
	while (ft_isdigit(str[i]) == 1 || (str[i] <= 'f' && str[i] >= 'a') || (str[i] <= 'F' && str[i] >= 'A'))
	{
		if (str[i] == '\0')
			return (res);
		res *= 16;
		if (ft_isdigit(str[i]) == 1)
			res += (str[i] - '0') * 16;
		else if (str[i] <= 'f' && str[i] >= 'a')
			res += (str[i] - 'a' + 10) * 16;
		else if (str[i] <= 'F' && str[i] >= 'A')
			res += (str[i] - 'A' + 10) * 16;
		i++;
	}
	return (res /= 16);
}

static int			ft_verif(char *str, int bo)
{
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		while (ft_isdigit(*str) == 1 && *str)
		{
			bo = 1;
			str++;
		}

		if (*str == ',' && bo == 1)
		{
			str++;
			if (*str != '0')
				return (0);
			else
				str++;
			if (*str != 'X' && *str != 'x')
				return (0);
			else
				str++;
			while (ft_ishexa(str) == 1)
				str++;
			if (*str != ' ' && ft_ishexa(str) == 0)
				return (0);
		}
		else if (*str == ' ')
			str++;
		else if (*str == '\0')
			return (1);
		else
			return (0);
		bo = 0;
	}
	return (1);
}


t_point				*ft_read_file(t_point *pnt, t_help *tmp, char *file, char *str)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	while (get_next_line(fd, &str) > 0)
	{
		ft_putendl("ici ?");
		ft_putendl(str);
		tmp->x = 0;
		if (ft_verif(str, 0) == 0)
			ft_error();
		while (*str)
		{
			while (*str == ' ' && *str)
				str++;
	ft_putendl("1 - 1");
			tmp->alt = ft_atoi(str);
	ft_putendl("1 - 2");
			while (ft_isdigit(*str) && *str)
				str++;
			if (*str == ',')
			{
				str += 3;
	ft_putendl("1 - 3");
				tmp->color = ft_atoihexa(str);
	ft_putendl("1 - 4");
				while (ft_ishexa(str) == 1)
					str++;
			}
			while (*str == ' ' && *str)
				str++;
	ft_putendl("1 - 5");
			ft_createpoint(&pnt, tmp);
			if (str == '\0')
			{
				ft_putendl("DEBUT");
				ft_putpoints(pnt);
			}
			tmp->color = 0;
			tmp->x++;
		}
		tmp->y++;
	}
	if (pnt == NULL)
		ft_error();
	return (pnt);
}
