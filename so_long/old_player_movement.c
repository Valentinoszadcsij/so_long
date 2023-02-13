/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:33:37 by voszadcs          #+#    #+#             */
/*   Updated: 2023/01/29 20:24:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

//listens to key press events
void	player_controls(mlx_key_data_t keydata, void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (player->animation_x == 0 && player->animation_y == 0)
	{
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		{
			player->animation_x += 24;
			player->cnt = 0;
		}
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		{
			player->animation_x -= 24;
			player->cnt = 3;
		}
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			player->animation_y += 24;
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		{
			player->animation_y -= 24;
		}
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(player->mlx);
}

void	move_right(t_player *player)
{
	int i = 0;
	player->animation_x -= 1;
	//printf("cnt : %d\n", player->cnt);
	player->character[player->cnt]->instances->x = player->x + 4;
	while (i < 3)
	{
		player->character[i]->instances->y = player->y;
		i++;
	}
	if (player->x % 32 == 0)
	{
		player->cnt++;
		if (player->cnt == 3)
		{
			player->cnt = 0;
		}
	}
	player->character[player->cnt]->instances->x = player->x + 4;
	//printf("location X: %d\n", player->x);
}

void	move_left(t_player *player)
{
	int i = 3;
	player->animation_x += 1;
	//printf("cnt : %d\n", player->cnt);
	player->character[player->cnt]->instances->x = player->x - 4;
	while (i < 6)
	{
		player->character[i]->instances->y = player->y;
		i++;
	}
	if (player->x % (-32) == 0)
	{
		player->cnt++;
		if (player->cnt == 6)
		{
			player->cnt = 3;
		}
	}
	player->character[player->cnt]->instances->x = player->x - 4;
	//printf("location X: %d\n", player->x);
	//printf("player->animation value: %d\n", player->animation_x);
}

void	move_up(t_player *player)
{
	player->animation_y -= 1;
	printf("cnt : %d\n", player->cnt);
	if (player->cnt < 3)
	{
		if (player->y % 32 == 0)
		{
			player->cnt++;
			if (player->cnt == 3)
				player->cnt = 0;
		}
		player->character[player->cnt]->instances->y = player->y - 4;
	}
	else
	{
		if (player->y % 32 == 0)
		{
			player->cnt++;
			if (player->cnt == 6)
				player->cnt = 3;
		}
		player->character[player->cnt]->instances->y = player->y - 4;
	}
	player->character[player->cnt]->instances->x = player->x;
}

void	move_down(t_player *player)
{
	player->animation_y += 1;
	printf("cnt : %d\n", player->cnt);
	if (player->cnt < 3)
	{
		if (player->y % 32 == 0)
		{
			player->cnt++;
			if (player->cnt == 3)
				player->cnt = 0;
		}
		player->character[player->cnt]->instances->y = player->y + 4;
	}
	else
	{
		if (player->y % 32 == 0)
		{
			player->cnt++;
			if (player->cnt == 6)
				player->cnt = 3;
		}
		player->character[player->cnt]->instances->y = player->y + 4;
	}
	player->character[player->cnt]->instances->x = player->x;
}
//moves character on key press applying movement animation
void	player_move(void *param)
{
	t_player	*player;

	player = param;
	player_img_enabled(player);
	if (player->animation_x > 0)
	{
		move_right(player);
	}
	else if (player->animation_x < 0)
	{
		move_left(player);
	}
	else if (player->animation_y < 0)
		move_down(player);
	else if (player->animation_y > 0)
		move_up(player);
	player->x = player->character[player->cnt]->instances->x;
	player->y = player->character[player->cnt]->instances->y;
	//printf("location X: %d\n", player->character[player->cnt]->instances->x);
	//printf("location Y: %d\n", player->character[player->cnt]->instances->y);
}