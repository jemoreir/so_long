/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:25 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 15:10:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_retangular(t_map *map)
{
	size_t	line;
	size_t	y;
	size_t	len_y;

	line = ft_linelen(map->grid[0]);
	y = 0;
	while(y < (map->linhas))
	{
		len_y = ft_linelen(map->grid[y]);
		if(len_y != line)
		{
			ft_putstr_fd("Error\nMapa não retangular.\n", 2);
			ft_free_map(map);
			return;
		}
		y++;
	}
}

void	ft_check_walls(t_map *map)
{
	int	y;

	y = 1;
	if(ft_check_line(map->grid[0], map) || ft_check_line(map->grid[map->linhas - 1], map))
		return;
	while(y < map->linhas - 1)
	{
		if((map->grid[y][0] != '1') || (map->grid[y][ft_linelen(map->grid[y]) - 1] != '1'))
		{
			ft_putstr_fd("Error\nMapa não fechado.\n", 2);
			ft_free_map(map);
			return;
		}
		y++;
	}
	return;
}

void	ft_check_elements(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while(y < map->linhas - 1)
	{
		while(x < ft_linelen(map->grid[y]) - 1)
		{
			if(map->grid[y][x] == 'P')
				map->players++;
			if(map->grid[y][x] == 'C')
				map->coletaveis++;
			if(map->grid[y][x] == 'E')
				map->saida++;
			x++;
		}
		x = 0;
		y++;
	}
	if(map->players != 1 || map->saida != 1 || map->coletaveis < 1)
	{
		ft_putstr_fd("Error\nMapa não fechado.\n", 2);
		ft_free_map(map);
		return;
	}
	return;
}

void	ft_check_invalid_chars(t_map *map)
{
	(void)map;
	// checar o personagem
}

void	ft_check_playable(t_map *map)
{
	(void)map;
	// checar se o player consegue alcancar os coletaveis e a saida
}
