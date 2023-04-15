/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:28:48 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:13:30 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_d(t_game *g, char *s)
{
	if (g->map->map_arr[g->player->y][g->player->x + 1] != '1')
	{
		s = ft_itoa(g->player->steps);
		if (g->textures->st1 != NULL && g->textures->st2 != NULL)
		{
			mlx_delete_image(g->mlx, g->textures->st1);
			mlx_delete_image(g->mlx, g->textures->st2);
		}
		g->player->x += 1;
		g->player->steps += 1;
		g->player->direction = RIGHT;
		ft_printf("Steps: %d\n", g->player->steps);
		g->textures->st1 = mlx_put_string(g->mlx,
				"Steps :", (0) * STEP, (g->map->y - 1) * STEP);
		g->textures->st2 = mlx_put_string(g->mlx, s, 120,
				(g->map->y - 1) * STEP);
		free(s);
	}
}

void	key_a(t_game *g, char *s)
{
	if (g->map->map_arr[g->player->y][g->player->x - 1] != '1')
	{
		s = ft_itoa(g->player->steps);
		if (g->textures->st1 != NULL && g->textures->st2 != NULL)
		{
			mlx_delete_image(g->mlx, g->textures->st1);
			mlx_delete_image(g->mlx, g->textures->st2);
		}
		g->player->x -= 1;
		g->player->steps += 1;
		g->player->direction = LEFT;
		ft_printf("Steps: %d\n", g->player->steps);
		g->textures->st1 = mlx_put_string(g->mlx,
				"Steps :", (0) * STEP, (g->map->y - 1) * STEP);
		g->textures->st2 = mlx_put_string(g->mlx, s, 120,
				(g->map->y - 1) * STEP);
		free(s);
	}
}

void	key_w(t_game *g, char *s)
{
	if (g->map->map_arr[g->player->y - 1][g->player->x] != '1')
	{
		s = ft_itoa(g->player->steps);
		if (g->textures->st1 != NULL && g->textures->st2 != NULL)
		{
			mlx_delete_image(g->mlx, g->textures->st1);
			mlx_delete_image(g->mlx, g->textures->st2);
		}
		g->player->y -= 1;
		g->player->steps += 1;
		ft_printf("Steps: %d\n", g->player->steps);
		g->textures->st1 = mlx_put_string(g->mlx,
				"Steps :", (0) * STEP, (g->map->y - 1) * STEP);
		g->textures->st2 = mlx_put_string(g->mlx, s,
				120, (g->map->y - 1) * STEP);
		free(s);
	}
}

void	key_s(t_game *g, char *s)
{
	if (g->map->map_arr[g->player->y + 1][g->player->x] != '1')
	{
		s = ft_itoa(g->player->steps);
		if (g->textures->st1 != NULL && g->textures->st2 != NULL)
		{
			mlx_delete_image(g->mlx, g->textures->st1);
			mlx_delete_image(g->mlx, g->textures->st2);
		}
		g->player->y += 1;
		g->player->steps += 1;
		ft_printf("Steps: %d\n", g->player->steps);
		g->textures->st1 = mlx_put_string(g->mlx,
				"Steps :", (0) * STEP, (g->map->y - 1) * STEP);
		g->textures->st2 = mlx_put_string(g->mlx, s,
				120, (g->map->y - 1) * STEP);
		free(s);
	}
}

void	keys(mlx_key_data_t key_data, void *game)
{
	t_game *const	g = game;
	char			*s;

	s = NULL;
	if (g->status == ACTIVE)
	{
		if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
			key_d(g, s);
		if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
			key_a(g, s);
		if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
			key_w(g, s);
		if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
			key_s(g, s);
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(g->mlx);
	}
}
