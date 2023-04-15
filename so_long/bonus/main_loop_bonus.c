/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:05:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 03:07:26 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->textures->sloth->count)
	{
		if (game->textures->sloth->instances[i].x == game->player->x * STEP
			&& game->textures->sloth->instances[i].y == game->player->y * STEP)
		game->textures->sloth->instances[i].enabled = false;
		i++;
	}
	game->map->map_arr[game->player->y][game->player->x] = '0';
	game->map->cnt_c--;
}

void	main_loop(void *game)
{
	t_game *const	g = game;

	g->frames++;
	if (g->status == ACTIVE)
		move(g->player);
	if (g->map->map_arr[g->player->y][g->player->x] == 'C')
		collect(g);
	if (g->map->cnt_c == 0 && g->map->map_arr[
			g->player->y][g->player->x] == 'E' && g->status == ACTIVE)
	{
		game_end(g);
		g->status = OVER;
	}
	if (g->enemy && g->status == ACTIVE)
	{
		if (g->enemy && g->frames >= 120)
			enemy_animation(g);
		if (g->player->x == g->enemy->x && g->player->y == g->enemy->y
			&& g->enemy->is_alive == true)
			player_die(g);
	}
	if (g->frames == 240)
		g->frames = 0;
}
