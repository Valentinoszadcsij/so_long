/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:12:59 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 04:15:13 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(mlx_t *mlx, t_player *player)
{
	mlx_texture_t	*buffer;

	buffer = mlx_load_png("textures/mage0.png");
	player->img = mlx_texture_to_image(mlx, buffer);
	mlx_delete_texture(buffer);
	mlx_image_to_window(
		mlx, player->img, player->x * 64, player->y * 64);
}

void	player_init(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	game->player->x = game->map->p_x;
	game->player->y = game->map->p_y;
	game->player->steps = 0;
	load_textures(game->mlx, game->player);
	game->status = ACTIVE;
}
