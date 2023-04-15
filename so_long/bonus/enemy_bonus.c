/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 04:49:58 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 03:22:57 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_enemy(t_game *g)
{
	mlx_image_to_window(g->mlx, g->textures->enemy[0],
		g->enemy->x * STEP, g->enemy->y * STEP);
	mlx_image_to_window(g->mlx, g->textures->enemy[1],
		g->enemy->x * STEP, g->enemy->y * STEP);
	mlx_image_to_window(g->mlx, g->textures->enemy[2],
		g->enemy->x * STEP, g->enemy->y * STEP);
	mlx_image_to_window(g->mlx, g->textures->enemy[3],
		g->enemy->x * STEP, g->enemy->y * STEP);
}

void	get_textures(mlx_t *mlx, t_textures *txt)
{
	txt->enemy = malloc(sizeof(mlx_image_t *) * 4);
	txt->enemy[0] = load_image("textures/l_drk_st1.png", mlx);
	txt->enemy[1] = load_image("textures/l_drk_st2.png", mlx);
	txt->enemy[2] = load_image("textures/l_drk_st3.png", mlx);
	txt->enemy[3] = load_image("textures/l_drk_st4.png", mlx);
}

void	is_enemy_pos(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->map->y)
	{
		while (j < g->map->x)
		{
			if (g->map->map_arr[i][j] == 'A')
			{
				g->enemy = malloc(sizeof(t_enemy));
				g->enemy->x = j;
				g->enemy->y = i;
				return ;
			}
			else
				j++;
			if (i == g->map->y - 1 && j == g->map->x - 1)
				g->enemy = NULL;
		}
		i++;
		j = 0;
	}
}

void	enemy_init(t_game	*g)
{
	is_enemy_pos(g);
	if (g->enemy)
	{
		get_textures(g->mlx, g->textures);
		draw_enemy(g);
	}
}
