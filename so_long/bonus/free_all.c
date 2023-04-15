/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:48:11 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:12:19 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_enemy(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_delete_image(g->mlx, g->textures->enemy[i]);
	free(g->textures->enemy);
	g->textures->enemy = NULL;
	free(g->enemy);
	g->enemy = NULL;
}

void	free_dead(t_game *g)
{
	mlx_delete_image(g->mlx, g->player->rip);
	mlx_delete_image(g->mlx, g->textures->door);
	if (g->map->x > 10 && g->map->y > 8)
		mlx_delete_image(g->mlx, g->textures->banner_dead_lrg);
	else
		mlx_delete_image(g->mlx, g->textures->banner_dead_sm);
	free_enemy(g);
}

void	free_alive(t_game *g)
{
	if (g->map->x > 10 && g->map->y > 8)
		mlx_delete_image(g->mlx, g->textures->banner_lrg);
	else
		mlx_delete_image(g->mlx, g->textures->banner_sm);
	mlx_delete_image(g->mlx, g->textures->door_open);
	mlx_delete_image(g->mlx, g->player->mage_away);
	if (g->enemy)
		free_enemy(g);
}

void	free_all(t_game *g)
{
	int	i;

	i = -1;
	if (g->player->is_dead == true)
		free_dead(g);
	else if (g->player->is_dead == false && g->status == OVER)
		free_alive(g);
	free(g->player);
	while (++i < g->map->y)
		free(g->map->map_arr[i]);
	free(g->map->map_arr);
	free(g->map);
	mlx_delete_image(g->mlx, g->textures->st1);
	mlx_delete_image(g->mlx, g->textures->st2);
	mlx_delete_image(g->mlx, g->textures->background);
	mlx_delete_image(g->mlx, g->textures->ground);
	mlx_delete_image(g->mlx, g->textures->wall);
	mlx_delete_image(g->mlx, g->textures->sloth);
	if (g->enemy)
		free_enemy(g);
	free(g->textures);
}
