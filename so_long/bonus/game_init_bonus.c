/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:32:09 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/25 21:29:33 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_init(t_game *param, char *path)
{	
	char	*dot;

	dot = ft_strchr(path, '.');
	if (!dot)
	{
		ft_printf("ERROR:\nMap file extension is wrong:\n");
		return (0);
	}
	if (ft_strncmp(".ber\0", ft_strchr(path, '.'), 4) != 0)
	{	
		ft_printf("||ERROR:\nMap file extension is wrong:||\n");
		return (0);
	}	
	param->map = malloc(sizeof(t_map));
	param->map->path = path;
	if (map_read(param) == 1)
		param->map->map_valid = map_check(param->map);
	if (param->map->map_valid == 1)
	{
		ft_printf ("||Map validation: SUCCESS||\n");
		return (1);
	}
	return (0);
}

int	game_init(char *path)
{
	t_game	game;

	if (map_init(&game, path) == 0)
		return (EXIT_FAILURE);
	game.mlx = mlx_init(game.map->x * 64, game.map->y * 64, "SO LONG", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	textures(&game);
	map_render(game.mlx, game.textures, game.map);
	player_init(&game);
	game.frames = 0;
	enemy_init(&game);
	mlx_key_hook(game.mlx, keys, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
