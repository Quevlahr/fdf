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

void			ft_putpoints(t_point *pt)
{
	while (pt)
	{
		ft_putnbr(pt->x);
		ft_putstr(" - ");
		ft_putnbr(pt->y);
		ft_putstr(" - ");
		ft_putnbr(pt->alt);
		ft_putstr(";\n");
		pt = pt->next;
	}
}

void			ft_createpoint(t_point **pt, int x, int y, int alt)
{
	t_point		*tmp;

	tmp = (t_point*)malloc(sizeof(t_point));
	tmp->x = x;
	tmp->y = y;
	tmp->alt = alt;
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

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			alt;
	t_point		*pt1;
	char		*str = NULL;
	int			fd = 0;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &str) > 0)
		{
			x = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
			y = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
			alt = ft_atoi(str);
			ft_createpoint(&pt1, x, y, alt);
		}
		while (pt1->prev)
			pt1 = pt1->prev;
		ft_putpoints(pt1);
		close(fd);
		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "Test_point");
		while (pt1->next)
		{
			x = pt1->x;
			y = pt1->y;
			if (x > pt1->next->x)
			{
				while (x > pt1->next->x)
				{
					mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
					x--;
				}
			}
			else
			{
				while (x < pt1->next->x)
				{
					mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
					x++;
				}
			}
			if (y > pt1->next->y)
			{
				while (y > pt1->next->y)
				{
					mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
					y--;
				}	
			}
			else
			{
				while (y < pt1->next->y)
				{
					mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
					y++;
				}
			}
			pt1 = pt1->next;
		}
		// ft_trace();
		mlx_loop(mlx);
	}
	return (1);
}
