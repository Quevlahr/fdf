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

#include "../fdf.h"

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
