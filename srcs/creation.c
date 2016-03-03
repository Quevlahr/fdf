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

#include "../fdf.h"

t_point				*ft_read_file(char *file, char *str)
{
	int				x;
	int				y;
	int				alt;
	int				fd;

	fd = open(file, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &str) > 0)
	{
		while (*str)
		{
			if (ft_verif(str))
			x++;
		}
		y++;
	}
}
