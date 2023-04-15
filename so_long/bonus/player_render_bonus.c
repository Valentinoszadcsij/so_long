/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:12:59 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 02:41:09 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_textures(mlx_t *mlx, t_player *player)
{
	player->img_left = load_image("textures/mage4.png", mlx);
	player->img_right = load_image("textures/mage0.png", mlx);
	player->rip = load_image("textures/rip.png", mlx);
	player->mage_away = load_image("textures/mage_away.png", mlx);
	mlx_image_to_window(
		mlx, player->img_right, player->x * 64, player->y * 64);
	mlx_image_to_window(
		mlx, player->img_left, player->x * 64, player->y * 64);
}

void	player_init(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	game->player->x = game->map->p_x;
	game->player->y = game->map->p_y;
	game->player->steps = 0;
	load_textures(game->mlx, game->player);
	if (game->player->x <= game->map->e_x)
		game->player->img_left->enabled = false;
	else
		game->player->img_right->enabled = false;
	game->player->is_dead = false;
	game->status = ACTIVE;
}
