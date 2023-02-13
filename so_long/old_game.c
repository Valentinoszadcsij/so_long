/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:35:43 by voszadcs          #+#    #+#             */
/*   Updated: 2023/01/31 22:09:02 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
// #define WIDTH 1024
// #define HEIGHT 780

int32_t	main(void)
{
	mlx_t			*mlx;
	t_player		*player;
	t_map			*map;

	map = map_init();
	mlx = mlx_init((int)map->width * 96, (int)map->height * 96, "Very long", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	//printf("x: %d; y: %d\n", map->width, map->height);
	map->mlx = mlx;
	fill_map_arr(map, map->height);
	map_textures(map);
	player = player_init(mlx);
	mlx_key_hook(mlx, &player_controls, player);
	mlx_loop_hook(mlx, player_move, player);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}