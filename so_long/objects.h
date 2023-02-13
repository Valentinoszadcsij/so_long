/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:39:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/02/13 20:20:42 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "so_long.h"

typedef struct s_map_cpy
{
	char	**map;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		cnt_c;
}	t_map_cpy;

typedef struct s_map
{
	int			x;
	int			y;
	int			fd;
	char		*path;
	char		**map_arr;
	int			cnt_p;
	int			cnt_c;
	int			cnt_e;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	t_map_cpy	*map_cpy;
	int			map_valid;
}	t_map;

typedef struct s_player
{
	mlx_image_t		**imgs;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_map			*map;
}	t_game;
#endif