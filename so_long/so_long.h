/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:48:39 by voszadcs          #+#    #+#             */
/*   Updated: 2023/02/11 21:13:13 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1024
# define HEIGHT 720
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <limits.h>
# include "lib/get_next_line/get_next_line.h"
# include "lib/MLX42/MLX42.h"
# include "objects.h"
//output text colors
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

// typedef struct s_player
// {
// 	mlx_image_t	**character;
// 	mlx_t		*mlx;
// 	int			x;
// 	int			y;
// 	int			cnt;
// 	int			animation_x;
// 	int			animation_y;
// }	t_player;

// typedef struct s_map
// {
// 	mlx_t		*mlx;
// 	char		**map_arr;
// 	mlx_image_t	*sloth;
// 	mlx_image_t	*tile;
// 	size_t		width;
// 	int			height;
// }	t_map;

t_game	game_init(char *path);
int		map_read(t_game *param);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		map_check(t_map *map);
int		check_path(t_map *map);

#endif