/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:32:09 by voszadcs          #+#    #+#             */
/*   Updated: 2023/02/13 20:02:09 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *param, char *path)
{
	char	ext[5];

	strcpy(ext, ".ber\0");
	if (ft_strncmp(ext, ft_strchr(path, '.'), 4) != 0)
	{	
		printf(RED "||ERROR:\nMap file extension is wrong:||\n");
		return ;
	}	
	param->map = malloc(sizeof(t_map));
	param->map->path = path;
	if (map_read(param) == 1)
	{
		param->map->map_valid = map_check(param->map);
		for (int i = 0; i < 5; i++)
		{
			printf("%s", param->map->map_arr[i]);
		}
		printf("\n\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%s\n", param->map->map_cpy->map[i]);
		}
	}
	if (param->map->map_valid == 1)
	{
		printf (GRN "||Map validation: SUCCESS||");
	}
}

t_game	game_init(char *path)
{
	t_game	game;

	game.mlx = mlx_init(WIDTH, HEIGHT, "SO LONG", true);
	map_init(&game, path);
	return (game);
}