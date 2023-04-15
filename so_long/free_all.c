/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 04:04:00 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 12:25:00 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->map->y)
		free(g->map->map_arr[i]);
	free(g->map->map_arr);
	free(g->map);
	free(g->player);
	free(g->textures);
}
