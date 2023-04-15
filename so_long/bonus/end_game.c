/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:47:04 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 03:53:19 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_end_bg(mlx_t *mlx, t_map *map, t_textures *txt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		while (map->map_arr[i][j] != '\0'
			&& map->map_arr[i][j] != '\n')
		{
			mlx_image_to_window(mlx, txt->background,
				j * STEP, i * STEP);
			j++;
		}
		i++;
		j = 0;
	}
}

void	put_banner(mlx_t *mlx, t_textures *txt, t_map *map, bool is_dead)
{
	draw_end_bg(mlx, map, txt);
	if (is_dead)
	{
		if (map->x > 10 && map->y > 8)
			mlx_image_to_window(mlx, txt->banner_dead_lrg,
				(map->x * STEP - 480) / 2, (map->y * STEP - 320) / 2);
		else
			mlx_image_to_window(mlx, txt->banner_dead_sm,
				(map->x * STEP - 240) / 2, (map->y * STEP - 160) / 2);
	}		
	else
	{
		if (map->x > 10 && map->y > 8)
			mlx_image_to_window(mlx, txt->banner_lrg,
				(map->x * STEP - 480) / 2, (map->y * STEP - 320) / 2);
		else
			mlx_image_to_window(mlx, txt->banner_sm,
				(map->x * STEP - 240) / 2, (map->y * STEP - 160) / 2);
	}
}

void	player_die(t_game *g)
{
	int	i;

	g->status = OVER;
	g->player->is_dead = true;
	i = 0;
	mlx_delete_image(g->mlx, g->player->img_left);
	mlx_delete_image(g->mlx, g->player->img_right);
	mlx_image_to_window(
		g->mlx, g->player->rip, g->player->x * 64, g->player->y * 64);
	put_banner(g->mlx, g->textures, g->map, g->player->is_dead);
}

void	game_end(t_game *g)
{
	mlx_delete_image(g->mlx, g->textures->door);
	mlx_delete_image(g->mlx, g->player->img_left);
	mlx_delete_image(g->mlx, g->player->img_right);
	mlx_image_to_window(g->mlx, g->textures->door_open,
		g->player->x * STEP, g->player->y * STEP);
	mlx_image_to_window(g->mlx, g->player->mage_away,
		(g->player->x * STEP + 28), (g->player->y * STEP) + 28);
	put_banner(g->mlx, g->textures, g->map, g->player->is_dead);
}
