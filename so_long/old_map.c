/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:42:26 by voszadcs          #+#    #+#             */
/*   Updated: 2023/01/30 18:01:19 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	count_lines(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: map file could't open");
		return (-1);
	}
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	if (line)
		i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

void	fill_map_arr(t_map *map, int cnt)
{
	int		fd;
	int		i;
	size_t	length;
	char	*output;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	while (i < cnt)
	{
		output = get_next_line(fd);
		length = ft_strlen(output);
		map->map_arr[i] = malloc(sizeof(char) * (length + 1));
		ft_memmove(map->map_arr[i], output, length);
		free(output);
		i++;
	}
	close(fd);
}

void	map_textures(t_map	*map)
{
	mlx_texture_t	*texture_sloth;
	mlx_texture_t	*texture_tile;
	int				i;
	int				chars;
	int				y;

	y = map->height;
	map->width = 0;
	map->height = 0;
	i = 0;
	chars = 0;
	texture_sloth = mlx_load_png("textures/sloth.png");
	texture_tile = mlx_load_png("textures/tiles.png");
	map->sloth = mlx_texture_to_image(map->mlx, texture_sloth);
	map->tile = mlx_texture_to_image(map->mlx, texture_tile);
	while (i < y)
	{
		while (map->map_arr[i][chars] == '0')
		{
			printf("$$lines: %d\n", map->height);
			mlx_image_to_window(map->mlx, map->tile, map->width, map->height);
			mlx_image_to_window(map->mlx, map->sloth, map->width, map->height);
			map->width += 96;
			chars++;
		}
		chars = 0;
		map->width = 0;
		i++;
		map->height += 96;
	}
}

t_map	*map_init(void)
{
	t_map			*map;

	map = malloc(sizeof(t_map));
	
	map->height = count_lines(map);
	map->map_arr = malloc(sizeof(char *) * map->height);
	//fill_map_arr (map, map->height);
	//map_textures(map);
	return (map);
}