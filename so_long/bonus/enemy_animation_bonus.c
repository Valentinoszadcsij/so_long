/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:02:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:07:48 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_spawn(t_textures *txt, t_enemy *enemy, int frame)
{
	if (frame == 200)
		txt->enemy[0]->enabled = true;
	if (frame == 210)
		txt->enemy[1]->enabled = true;
	if (frame == 220)
		txt->enemy[2]->enabled = true;
	if (frame == 230)
	{
		txt->enemy[3]->enabled = true;
		enemy->is_alive = true;
	}
}

void	enemy_fade(t_textures *txt, t_enemy *enemy, int frame)
{
	if (frame == 120)
		txt->enemy[3]->enabled = false;
	if (frame == 130)
		txt->enemy[2]->enabled = false;
	if (frame == 140)
		txt->enemy[1]->enabled = false;
	if (frame == 150)
	{
		txt->enemy[0]->enabled = false;
		enemy->is_alive = false;
	}
}

void	enemy_animation(t_game *g)
{
	enemy_fade(g->textures, g->enemy, g->frames);
	if (g->frames >= 200)
		enemy_spawn(g->textures, g->enemy, g->frames);
}
