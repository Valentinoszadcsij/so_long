/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:28:48 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 17:49:08 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_d(t_game *g)
{
	if (g->map->map_arr[g->player->y][g->player->x + 1] != '1')
	{
		g->player->x += 1;
		g->player->steps += 1;
		ft_printf("Steps: %d\n", g->player->steps);
	}
}

void	key_a(t_game *g)
{
	if (g->map->map_arr[g->player->y][g->player->x - 1] != '1')
	{
		g->player->x -= 1;
		g->player->steps += 1;
		ft_printf("Steps: %d\n", g->player->steps);
	}
}

void	key_w(t_game *g)
{
	if (g->map->map_arr[g->player->y - 1][g->player->x] != '1')
	{
		g->player->y -= 1;
		g->player->steps += 1;
		ft_printf("Steps: %d\n", g->player->steps);
	}
}

void	key_s(t_game *g)
{
	if (g->map->map_arr[g->player->y + 1][g->player->x] != '1')
	{
		g->player->y += 1;
		g->player->steps += 1;
		ft_printf("Steps: %d\n", g->player->steps);
	}
}

void	keys(mlx_key_data_t key_data, void *game)
{
	t_game *const	g = game;

	if (g->status == ACTIVE)
	{
		if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
			key_d(g);
		if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
			key_a(g);
		if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
			key_w(g);
		if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
			key_s(g);
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
}
