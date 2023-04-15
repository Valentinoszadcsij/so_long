/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:33:20 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 17:49:29 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cnt(t_map *map)
{
	int	i;

	i = 0;
	map->cnt_c = 0;
	map->cnt_e = 0;
	map->cnt_p = 0;
	while (i++ < map->y - 1)
	{
		while (*map->map_arr[i] != '\n' && *map->map_arr[i] != '\0')
		{
			if (*map->map_arr[i] == 'P')
				map->cnt_p++;
			else if (*map->map_arr[i] == 'C')
				map->cnt_c++;
			else if (*map->map_arr[i] == 'E')
				map->cnt_e++;
			map->map_arr[i]++;
		}
		map->map_arr[i] = map->map_arr[i] - map->x;
	}
	if (map->cnt_c >= 1 && map->cnt_e == 1 && map->cnt_p == 1)
		return (1);
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	if (ft_strchr(map->map_arr[map->y - 1], '\n'))
		map->x--;
	while (i < map->x)
	{
		if (map->map_arr[0][i] != '1' || map->map_arr[map->y - 1][i] != '1')
		{
			ft_printf("ERROR:\nMap has to be surrounded by wall (1)\n");
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < map->y - 1)
	{
		if (map->map_arr[i][0] != '1' || map->map_arr[i][map->x - 1] != '1')
		{
			ft_printf("ERROR:\nMap has to be surrounded by wall (1)||\n");
			return (0);
		}
		i++;
	}
	return (1);
}
//Here only have to check from second to one before last lines
// as 1st and last have to contain only '1' and checked in check_walls

int	check_chars(t_map *map)
{
	char	symbols[6];
	int		i;
	int		j;

	i = 1;
	j = 0;
	strcpy(symbols, "01CEP\0");
	while (i != map->y - 1)
	{
		while (map->map_arr[i][j] != '\n' && map->map_arr[i][j] != '\0')
		{	
			if (ft_strchr(symbols, map->map_arr[i][j]) == NULL)
			{
				ft_printf("ERROR:\nWrong symbol(s) in map file\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	map_check(t_map *map)
{
	if (check_chars(map) == 0 || check_walls(map) == 0)
		return (0);
	else if (check_cnt(map) == 0)
	{
		ft_printf("ERROR:\nCheck the game objects count\n");
		return (0);
	}
	else if (check_path(map) == 0)
	{
		ft_printf("ERROR\nThere is no valid path\n");
		return (0);
	}
	else
		return (1);
}
