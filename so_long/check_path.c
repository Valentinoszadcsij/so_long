/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:25:00 by voszadcs          #+#    #+#             */
/*   Updated: 2023/02/13 20:25:57 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map->map_cpy->x = map->x;
	map->map_cpy->y = map->y;
	map->map_cpy->cnt_c = map->cnt_c;
}

bool	dfs(t_map_cpy *map)
{
	if (map->map[map->p_y][map->p_x] == 'E')
		return (true);
	map->map[map->p_y][map->p_x] = '2';
	if (map->map[map->p_y][map->p_x+1] != '1' && map->map[map->p_y][map->p_x+1] != '2')
	{
		map->p_x = map->p_x+1;
		printf("x:%d, y:%d\n", map->p_x, map->p_y);
		if (dfs(map))
			return (true);
		map->p_x = map->p_x-1;
	}
	if (map->map[map->p_y+1][map->p_x] != '1' && map->map[map->p_y+1][map->p_x] != '2')
	{
		map->p_y = map->p_y+1;
		printf("x:%d, y:%d\n", map->p_x, map->p_y);
		if (dfs(map))
			return (true);
		map->p_y = map->p_y-1;
	}
	if (map->map[map->p_y][map->p_x-1] != '1' && map->map[map->p_y][map->p_x-1] != '2')
	{
		map->p_x = map->p_x-1;
		printf("x:%d, y:%d\n", map->p_x, map->p_y);
		if (dfs(map))
			return (true);
		map->p_x = map->p_x+1;
	}
	if (map->map[map->p_y-1][map->p_x] != '1' && map->map[map->p_y-1][map->p_x] != '2')
	{
		map->p_y = map->p_y-1;
		printf("x:%d, y:%d\n", map->p_x, map->p_y);
		if (dfs(map))
			return (true);
		map->p_y = map->p_y+1;
	}
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
	printf(MAG " p: %d, %d\n", map->p_x, map->p_y);
	if (dfs(map->map_cpy) == true)
		return (1);
	return (0);
}