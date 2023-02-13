/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:32:15 by voszadcs          #+#    #+#             */
/*   Updated: 2023/01/17 21:14:47 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*remaining_buffer(char *buffer)
{
	char	*temp;

	if (buffer)
	{
		temp = malloc(sizeof(char) * ft_strlen(buffer) + 1);
		if (!temp)
			return (NULL);
		ft_memmove(temp, buffer, ft_strlen(buffer));
		return (temp);
	}
	else
		return (NULL);
}

char	*get_output_line(char *buffer)
{
	int		i;
	char	*output;

	i = 0;
	if (buffer != NULL && buffer[0] != '\0')
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
			i++;
		output = malloc(sizeof(char) * i + 1);
		if (!output)
			return (NULL);
		ft_memmove(output, buffer, i);
		return (output);
	}
	else
		return (NULL);
}

char	*no_read(char *read_value, char *buffer, int read_size)
{
	if (read_size == 0 && buffer[0] != '\0')
	{
		free(read_value);
		return (buffer);
	}
	else
	{
		free(read_value);
		free(buffer);
		return (NULL);
	}
}

char	*read_fd(int fd, char *buffer)
{
	int		read_size;
	char	*read_value;
	char	*temp;

	read_size = 1;
	while (read_size > 0 && !ft_strchr(buffer, '\n'))
	{
		read_value = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!read_value)
			return (NULL);
		read_size = read(fd, read_value, BUFFER_SIZE);
		if (read_size <= 0)
			return (no_read(read_value, buffer, read_size));
		read_value[read_size] = '\0';
		temp = ft_strjoin(buffer, read_value);
		if (!temp)
			return (NULL);
		free(read_value);
		free(buffer);
		buffer = ft_strjoin(NULL, temp);
		free(temp);
		if (read_size < BUFFER_SIZE)
			read_size = 0;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	char		*output_line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char) * 1);
		buffer[fd][0] = '\0';
	}
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_fd(fd, buffer[fd]);
	output_line = get_output_line(buffer[fd]);
	temp = buffer[fd];
	buffer[fd] = remaining_buffer(&buffer[fd][ft_strlen(output_line)]);
	free(temp);
	if (!output_line || output_line[0] == '\0')
	{
		free(buffer[fd]);
		return (NULL);
	}
	return (output_line);
}

// int main (void)
// {
// 	int fd;
// 	int i = 0;
// 	char *result;

// 	fd = open("input.txt", O_RDONLY);
// 	while (i < 4)
// 	{
// 		result = get_next_line(fd);
// 		printf(">>Output: %s", result);
// 		free(result);
// 		i++;
// 	}
// 	printf("%s", "//**//");
// }