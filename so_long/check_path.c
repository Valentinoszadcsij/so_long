/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:25:00 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 12:32:08 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	dfs(t_map_cpy *map);

void	map_cpy(t_map *map)
{
	int	i;

	i = 0;
	map->map_cpy = malloc(sizeof(t_map_cpy));
	map->map_cpy->map = malloc(sizeof(char *) * (map->y));
	while (i < map->y)
	{
		map->map_cpy->map[i] = malloc(sizeof(char) * (map->x + 1));
		ft_memmove(map->map_cpy->map[i], map->map_arr[i], map->x);
		i++;
	}
	map->map_cpy->p_x = map->p_x;
	map->map_cpy->p_y = map->p_y;
	map->map_cpy->cnt_c = map->cnt_c;
	map->map_cpy->vis = 50;
}

bool	dfs_step(t_map_cpy *map, int x, int y)
{
	if ((map->map[map->p_y + y][map->p_x + x] != '1') \
		&& (map->map[map->p_y + y][map->p_x + x] != map->vis))
	{
		map->p_x = map->p_x + x;
		map->p_y = map->p_y + y;
		if (dfs(map))
			return (true);
		map->p_x = map->p_x - x;
		map->p_y = map->p_y - y;
	}
	return (false);
}

bool	dfs(t_map_cpy *map)
{
	if (map->map[map->p_y][map->p_x] == 'C')
	{
		map->vis++;
		if (map->vis == 58)
			map->vis = 50;
		map->cnt_c--;
	}
	if (map->cnt_c == 0 && map->map[map->p_y][map->p_x] == 'E')
		return (true);
	else if (map->map[map->p_y][map->p_x] == 'E')
		map->map[map->p_y][map->p_x] = 'E';
	else
		map->map[map->p_y][map->p_x] = map->vis;
	if (dfs_step(map, 1, 0) || dfs_step(map, 0, 1) || \
		dfs_step(map, -1, 0) || dfs_step(map, 0, -1))
		return (true);
	return (false);
}

void	find_pos(t_map *map, int i, int j)
{
	if (map->map_arr[i][j] == 'P')
	{
		map->p_y = i;
		map->p_x = j;
	}
	else if (map->map_arr[i][j] == 'E')
	{
		map->e_y = i;
		map->e_x = j;
	}
}

int	check_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < (map->y - 1))
	{
		while (map->map_arr[i][j] != '\n' && map->map_arr[i][j] != '\0')
		{
			find_pos(map, i, j);
			j++;
		}
		j = 0;
	}
	map_cpy(map);
	i = -1;
	if (dfs(map->map_cpy) == true)
	{
		while (++i < map->y)
			free (map->map_cpy->map[i]);
		free(map->map_cpy->map);
		free(map->map_cpy);
		return (1);
	}
	return (0);
}
