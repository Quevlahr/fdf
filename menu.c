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

static void		ft_help_menu1(t_env env)
{
	char		*str1;
	char		*str2;
	char		*str3;

	str1 = ft_strnew(16);
	ft_strcpy(str1, "'m' for the menu");
	str2 = ft_strnew(29);
	ft_strcpy(str2, "'0' for the starting position");
	str3 = ft_strnew(32);
	ft_strcpy(str3, "'-' and '=' to change the height");
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str1) / 2) * 10
		, 0, 0xffffff, str1);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str2) / 2) * 10
		, 20, 0xffffff, str2);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str3) / 2) * 10
		, 40, 0xffffff, str3);
	ft_strdel(&str1);
	ft_strdel(&str2);
	ft_strdel(&str3);
}

void			ft_menu1(t_env env)
{
	char		*str1;
	char		*str2;
	char		*str3;

	str1 = ft_strnew(21);
	ft_strcpy(str1, "arrows to move around");
	str2 = ft_strnew(49);
	ft_strcpy(str2, "'+' and '-' on the keypad to zoom in and zoom out");
	str3 = ft_strnew(19);
	ft_strcpy(str3, "'space' to continue");
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str1) / 2) * 10
		, 60, 0xffffff, str1);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str2) / 2) * 10
		, 80, 0xffffff, str2);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str3) / 2) * 10
		, 100, 0xffffff, str3);
	ft_help_menu1(env);
	ft_strdel(&str1);
	ft_strdel(&str2);
	ft_strdel(&str3);
}

void			ft_menu(t_env env)
{
	char		*str1;
	char		*str2;
	char		*str3;
	char		*str4;

	str1 = ft_strnew(5);
	ft_strcpy(str1, "Hello");
	str2 = ft_strnew(14);
	ft_strcpy(str2, "Welcome to FdF");
	str3 = ft_strnew(16);
	ft_strcpy(str3, "'space' to start");
	str4 = ft_strnew(16);
	ft_strcpy(str4, "'m' for the menu");
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str1) / 2) * 10
		, 0, 0xffffff, str1);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str2) / 2) * 10
		, 20, 0xffffff, str2);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str3) / 2) * 10
		, 40, 0xffffff, str3);
	mlx_string_put(env.mlx, env.win, env.len_x / 2 - (ft_strlen(str4) / 2) * 10
		, 60, 0xffffff, str4);
	ft_strdel(&str1);
	ft_strdel(&str2);
	ft_strdel(&str3);
	ft_strdel(&str4);
}
