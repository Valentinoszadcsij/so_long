/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:03:39 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 03:17:27 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*load_image(char *path, mlx_t *mlx)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;

	txt = mlx_load_png(path);
	img = mlx_texture_to_image(mlx, txt);
	mlx_delete_texture(txt);
	return (img);
}

void	textures_to_image(mlx_t *mlx, t_textures *txt)
{
	txt->st1 = NULL;
	txt->st2 = NULL;
	txt->background = load_image("textures/bg.png", mlx);
	txt->banner_lrg = load_image("textures/success_lrg.png", mlx);
	txt->banner_sm = load_image("textures/success_sm.png", mlx);
	txt->banner_dead_lrg = load_image("textures/game_over_lrg.png", mlx);
	txt->banner_dead_sm = load_image("textures/game_over_sm.png", mlx);
	txt->sloth = load_image("textures/sloth.png", mlx);
	txt->wall = load_image("textures/wall.png", mlx);
	txt->ground = load_image("textures/ground.png", mlx);
	txt->door = load_image("textures/door.png", mlx);
	txt->door_open = load_image("textures/door_open.png", mlx);
}

void	textures(t_game *g)
{
	g->textures = malloc(sizeof(t_textures));
	if (!g->textures)
		return ;
	textures_to_image(g->mlx, g->textures);
}
