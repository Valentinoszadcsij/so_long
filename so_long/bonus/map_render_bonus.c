/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:58:04 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/11 05:23:23 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_render(mlx_t *mlx, t_textures *txt, t_map *map)
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
}
