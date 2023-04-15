/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:05:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 17:50:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	move(g);
	if (g->map->map_arr[g->player->y][g->player->x] == 'C')
		collect(g);
	if (g->map->cnt_c == 0 && g->map->map_arr[
			g->player->y][g->player->x] == 'E')
	{
		g->textures->door->enabled = false;
		if (g->status == ACTIVE)
			ft_printf("Well done, you saved all slothies");
		g->status = OVER;
	}
}
