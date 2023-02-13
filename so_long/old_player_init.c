/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:18:31 by voszadcs          #+#    #+#             */
/*   Updated: 2023/01/29 02:51:05 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

//loads textures from our source images and stores in *texture[6]
static void	player_textures(mlx_texture_t **texture)
{
	char			img_path[30];
	int				img_count;

	img_count = 0;
	while (img_count <= 5)
	{
		if (img_count < 3)
		{
			sprintf(img_path, "textures/mage_right_%d.png", img_count);
			texture[img_count] = mlx_load_png(img_path);
			img_count++;
		}
		else if (img_count >= 3 && img_count <= 5)
		{
			sprintf(img_path, "textures/mage_left_%d.png", img_count);
			texture[img_count] = mlx_load_png(img_path);
			img_count++;
		}
	}
}

//Loads textures to images stored in player->character and then 
//renders them with mlx_image_to_window
static void	player_render(t_player *player, mlx_texture_t **texture)
{
	int			i;
	t_player	*p;

	p = player;
	i = 0;
	p->character = malloc(sizeof(mlx_image_t **) * 6);
	while (i < 6)
	{
		p->character[i] = mlx_texture_to_image(p->mlx, texture[i]);
		if (i > 0)
			p->character[i]->enabled = false;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(p->mlx, p->character[i], p->x, p->y);
		i++;
	}
}

//enables current image to render and disables the rest
//called from player_move() func
void	player_img_enabled(t_player *player)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (player->cnt == i)
		{
			player->character[i]->enabled = true;
		}
		else
			player->character[i]->enabled = false;
		i++;
	}
	i = 0;
}

//initializes player struct
t_player	*player_init(void *param)
{
	mlx_texture_t	*texture[6];
	t_player		*player;
	mlx_t			*mlx;
	int				img_count;
	int				i;

	mlx = (mlx_t *)param;
	img_count = 0;
	i = 0;
	player_textures(texture);
	player = malloc(sizeof(t_player));
	player->mlx = mlx;
	player->x = 0;
	player->y = 0;
	player->cnt = 0;
	player->animation_x = 0;
	player->animation_y = 0;
	player_render(player, texture);
	return (player);
}
