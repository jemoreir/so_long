/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:28:53 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 16:28:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	int	fd;
	int	count;
	char *line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(0);
	while((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return(count);
}

char	**count_large(char *file, int *lines, int *col)
{
	int		fd;
	int		i;
	char	**grade;
	char	*line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		return NULL;
	*lines = count_line(file);
	grade = malloc(sizeof(char *) * (*lines));
	if (!grade)
		return NULL;
	i = 0;
	while((line = get_next_line(fd)))
	{
		grade[i] = line;
		if(i == 0)
			*col = 0;
		while(line[*col])
			*col++;
		i++;
	}
	close(fd);
	return grade;
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	map->player_x = -1;
	map->player_y = -1;
	map->coletaveis = 0;
	x = 0;
	y = 0;
	while(y < map->linhas)
	{
		while(x < map->colunas)
		{
			if(map->grid[x][y] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			else if(map->grid[x][y] == 'C')
				map->coletaveis++;
			x++;
		}
		y++;
	}
}
