/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:54:54 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/09 23:37:29 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game)
{
	game->player->img->instances->x = game->player->x * STEP;
	game->player->img->instances->y = game->player->y * STEP;
}
