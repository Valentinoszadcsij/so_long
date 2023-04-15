/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:48:39 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:11:17 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//game vars
# define WIDTH 1024
# define HEIGHT 720
# define STEP 64
# define ACTIVE 0
# define OVER 1
# define LEFT -1
# define RIGHT 1
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
# include "objects_bonus.h"

int			game_init(char *path);
int			map_read(t_game *param);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			map_check(t_map *map);
int			check_path(t_map *map);
void		textures(t_game *g);
void		map_render(mlx_t *mlx, t_textures *txt, t_map *map);
void		player_init(t_game *game);
void		keys(mlx_key_data_t key_data, void *game);
void		move(t_player *player);
void		main_loop(void *game);
char		*ft_itoa(int n);
void		enemy_init(t_game	*g);
void		enemy_animation(t_game *g);
void		game_end(t_game *g);
void		player_die(t_game *g);
void		free_all(t_game *g);
mlx_image_t	*load_image(char *path, mlx_t *mlx);

#endif