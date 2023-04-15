/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:39:36 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 00:44:44 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H
# include "so_long_bonus.h"

typedef struct s_map_cpy
{
	char	**map;
	int		p_x;
	int		p_y;
	int		cnt_c;
	char	vis;
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
	int			cnt_a;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	t_map_cpy	*map_cpy;
	int			map_valid;
}	t_map;

typedef struct s_player
{
	mlx_image_t		*img_right;
	mlx_image_t		*img_left;
	mlx_image_t		*rip;
	mlx_image_t		*mage_away;
	int				x;
	int				y;
	int				direction;
	bool			is_dead;
	int				steps;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	bool	is_alive;
}	t_enemy;

typedef struct s_textures
{
	mlx_image_t	*wall;
	mlx_image_t	*ground;
	mlx_image_t	*sloth;
	mlx_image_t	*door;
	mlx_image_t	*door_open;
	mlx_image_t	*banner_lrg;
	mlx_image_t	*banner_sm;
	mlx_image_t	*st1;
	mlx_image_t	*st2;
	mlx_image_t	*banner_dead_lrg;
	mlx_image_t	*banner_dead_sm;
	mlx_image_t	*background;
	mlx_image_t	**enemy;
}	t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player		*player;
	t_enemy			*enemy;
	t_map			*map;
	t_textures		*textures;
	int				status;
	int				frames;
}	t_game;
#endif