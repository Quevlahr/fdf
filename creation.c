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

static int			ft_ishexa(char *str)
{

		ft_putchar(*str);
		ft_putchar('\n');
		if (ft_isdigit(*str) == 1 || (*str <= 'f' && *str >= 'a') || (*str <= 'F' && *str >= 'A'))
		{
			return (1);
		}
		else
			return (0);

}

void				ft_createpoint(t_point **pt, int x, int y, int alt)
{
	t_point			*tmp;

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
			{
			ft_putstr("1");
			ft_putchar(*str);
			ft_putstr("1");
				return (0);
			}
			else
				str++;
			if (*str != 'X' && *str != 'x')
			{
			ft_putstr("2");
			ft_putchar(*str);
			ft_putstr("2");
				return (0);
			}
			else
				str++;
			while (ft_ishexa(str) == 1)
				str++;
			if (*str != ' ' && ft_ishexa(str) == 0)
			{
			ft_putstr("3");
			ft_putchar(*str);
			ft_putstr("3");
				return (0);
			}
		}
		else if (*str == ' ')
			str++;
		else if (*str == '\0')
			return (1);
		else
		{
			ft_putstr("4");
			ft_putchar(*str);
			ft_putstr("4");
			return (0);
		}
		ft_putendl(str);
		bo = 0;
	}
	return (1);
}

t_point				*ft_read_file(t_point *pt1, t_help *tmp, char *file, char *str)
{
	int				fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		// ft_putendl(str);
		tmp->x = 0;
		if (ft_verif(str, 0) == 0)
			ft_error();
		while (*str)
		{
			while (*str == ' ' && *str)
				str++;
			tmp->alt = ft_atoi(str);
			while (ft_isdigit(*str) && *str)
				str++;
			if (*str == ',')
			{
				str++;
				// tmp->color = ft_atoihexa(str); 
				while (ft_ishexa(str) == 1)
					str++;
			}
			while (*str == ' ' && *str)
				str++;
			ft_createpoint(&pt1, tmp->x, tmp->y, tmp->alt);
			tmp->x++;
		}
		tmp->y++;
	}
	return (pt1);
}
