/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:02:00 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/14 20:02:02 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_menu(t_tool tool)
{
	char		*str1;
	char		*str2;
	char		*str3;

	str1 = ft_strnew(8);
	ft_strcpy(str1, "Bonjour");
	str2 = ft_strnew(35);
	ft_strcpy(str2, "Bienvenue sur le projet Fil de Fer");
	str3 = ft_strnew(87);
	ft_strcpy(str3, "Appuyez sur espace pour commencer et sur m pour le menu");
	mlx_string_put(tool.mlx, tool.win, LENGTH / 2 - (ft_strlen(str1) / 2) * 10, 0, 0xffffff, str1);
	mlx_string_put(tool.mlx, tool.win, LENGTH / 2 - (ft_strlen(str2) / 2) * 10, 20, 0xffffff, str2);
	mlx_string_put(tool.mlx, tool.win, LENGTH / 2 - (ft_strlen(str3) / 2) * 10, 40, 0xffffff, str3);
}
