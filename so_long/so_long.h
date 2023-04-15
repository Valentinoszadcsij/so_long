/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:48:39 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:38:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//game vars
# define WIDTH 1024
# define HEIGHT 720
# define STEP 64
# define ACTIVE 0
# define OVER 1
//headers
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <limits.h>
# include "lib/get_next_line/get_next_line.h"
# include "lib/MLX42/MLX42.h"
# include "lib/ft_printf/ft_printf.h"
# include "objects.h"

int		game_init(char *path);
int		map_read(t_game *param);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		map_check(t_map *map);
int		check_path(t_map *map);
int		map_render(t_game *game);
void	player_init(t_game *game);
void	keys(mlx_key_data_t key_data, void *game);
void	move(t_game *game);
void	main_loop(void *game);
void	free_all(t_game *g);

#endif