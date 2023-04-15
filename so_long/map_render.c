/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:58:04 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 17:50:09 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(mlx_t *mlx, t_textures *txt, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (map->map_arr[i][j] != '\0' && map->map_arr[i][j] != '\n')
		{
			if (map->map_arr[i][j] != '1')
				mlx_image_to_window(mlx, txt->ground, (j) * STEP, (i) * STEP);
			if (map->map_arr[i][j] == 'C')
				mlx_image_to_window(mlx, txt->sloth, (j) * STEP, (i) * STEP);
			else if (map->map_arr[i][j] == '1')
				mlx_image_to_window(mlx, txt->wall, (j) * STEP, (i) * STEP);
			else if (map->map_arr[i][j] == 'E')
				mlx_image_to_window(mlx, txt->door, (j) * STEP, (i) * STEP);
			j++;
		}
	i++;
	j = 0;
	}
	return (1);
}

int	get_textures(mlx_t *mlx, t_textures *txt)
{
	mlx_texture_t	*buffer;

	buffer = mlx_load_png("textures/sloth.png");
	txt->sloth = mlx_texture_to_image(mlx, buffer);
	mlx_delete_texture(buffer);
	buffer = mlx_load_png("textures/ground.png");
	txt->ground = mlx_texture_to_image(mlx, buffer);
	mlx_delete_texture(buffer);
	buffer = mlx_load_png("textures/wall.png");
	txt->wall = mlx_texture_to_image(mlx, buffer);
	mlx_delete_texture(buffer);
	buffer = mlx_load_png("textures/door.png");
	txt->door = mlx_texture_to_image(mlx, buffer);
	mlx_delete_texture(buffer);
	return (1);
}

int	map_render(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (0);
	if (get_textures(game->mlx, game->textures) == 0)
	{
		ft_printf("Error: Failed to load textures\n");
		return (0);
	}
	if (render(game->mlx, game->textures, game->map) == 0)
		return (0);
	return (1);
}
