/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:05:20 by jemoreir          #+#    #+#             */
/*   Updated: 2025/11/07 18:05:20 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**count_large(char *file)
{
	int		fd;
	int		i;
	char	**grade;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grade = malloc(sizeof(char *) * (count_line(file) + 1));
	if (!grade)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_linelen(line) - 1]
			== '\n' || line[ft_linelen(line) - 1] == '\r')
			line[ft_linelen(line) - 1] = '\0';
		grade[i] = line;
		i++;
		line = get_next_line(fd);
	}
	grade[i] = NULL;
	close(fd);
	return (grade);
}

void	find_player(t_map *map)
{
	int	x;
	int	y;

	map->player_x = -1;
	map->player_y = -1;
	map->coletaveis = 0;
	y = 0;
	while (y < map->linhas)
	{
		x = 0;
		while (x < map->colunas)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'C')
				map->coletaveis++;
			x++;
		}
		y++;
	}
}

t_map	*load(char *file)
{
	t_map	*mapa;

	mapa = malloc(sizeof(t_map));
	if (!mapa)
		return (NULL);
	ft_init_map(mapa);
	mapa->grid = count_large(file);
	if (!mapa->grid)
		ft_free_error(mapa, NULL);
	mapa->linhas = count_line(file);
	mapa->colunas = ft_linelen(mapa->grid[0]);
	if (!mapa->grid || mapa->linhas == 0)
		ft_free_error(mapa, "mapa vazio");
	find_player(mapa);
	return (mapa);
}

int	ft_linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}
