/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:53:51 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 17:50:03 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cols(t_map *map, int i)
{
	map->x = (int)ft_strlen(map->map_arr[i]);
	if (map->x < 4)
	{
		ft_printf("ERROR:\nMap has less than 4 columns\n");
		return (0);
	}
	else if (map->x != (int)ft_strlen(map->map_arr[i - 1]))
	{
		if (i == map->y - 1 && !ft_strchr(map->map_arr[i], '\n'))
			return (1);
		ft_printf("||ERROR:\nMap lines length doesn't match\n");
		return (0);
	}
	else
		return (1);
}

int	save_arr(t_map *map)
{
	int	i;

	i = 0;
	map->map_arr = malloc(sizeof(void *) * (map->y));
	if (!map->map_arr)
	{
		ft_printf("Error:\nFailed to malloc map_arr\n");
		return (0);
	}
	map->fd = open(map->path, O_RDONLY);
	if (map->fd < 0)
		return (0);
	while (i < map->y)
	{
		map->map_arr[i] = get_next_line(map->fd);
		ft_printf("line %d: %s\n", i, map->map_arr[i]);
		if (i >= 1)
		{	
			if (check_cols(map, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	map_parse(t_map *map)
{
	char	*result;
	char	*temp;

	map->y = -1;
	result = get_next_line(map->fd);
	map->y++;
	while (result)
	{
		temp = result;
		result = get_next_line(map->fd);
		map->y++;
		free(temp);
	}
	free(result);
	close(map->fd);
	if (map->y < 3)
	{
		ft_printf("ERROR:\nMap cannot have less than 3 lines\n");
		return (0);
	}
	else if (save_arr(map) == 1)
		return (1);
	else
		return (0);
}

int	map_read(t_game *param)
{
	param->map->fd = open(param->map->path, O_RDONLY);
	if (param->map->fd < 0)
	{
		ft_printf("ERROR:\nFailed to open map file\n");
		return (0);
	}
	else if (map_parse(param->map) == 1)
	{
		ft_printf("Map parse: SUCCESS\n");
		return (1);
	}
	else
	{
		ft_printf("ERROR:\nFailed to parse map\n");
		return (0);
	}
}
