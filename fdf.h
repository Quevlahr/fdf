/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:07:30 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/21 17:07:38 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <stdlib.h>

typedef struct			s_point
{
	int					x;
	int					y;
	int					alt;
	struct s_point		*next;
	struct s_point		*prev;
}						t_point;

int				main(void);
int				ft_trace(void);

#endif
