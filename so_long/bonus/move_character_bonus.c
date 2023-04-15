/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:54:54 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/20 14:56:09 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move(t_player *player)
{
	player->img_left->instances->x = player->x * STEP;
	player->img_left->instances->y = player->y * STEP;
	player->img_right->instances->x = player->x * STEP;
	player->img_right->instances->y = player->y * STEP;
	if (player->direction == LEFT)
	{
		player->img_right->enabled = false;
		player->img_left->enabled = true;
	}
	else
	{
		player->img_right->enabled = true;
		player->img_left->enabled = false;
	}
}
