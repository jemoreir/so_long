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
	int	line;
	int	y;
	int	len_y;

	line = ft_linelen(map->grid[0]);
	y = 0;
	while (y < (map->linhas))
	{
		len_y = ft_linelen(map->grid[y]);
		if (len_y != line)
			ft_free_Error(map, "Erro\nMapa não retangular.\n");
		y++;
	}
}

void	ft_check_walls(t_map *map)
{
	int	y;

	y = 1;
	if (ft_check_line(map->grid[0], map)
		|| ft_check_line(map->grid[map->linhas - 1], map))
		return ;
	while (y < map->linhas - 1)
	{
		if ((map->grid[y][0] != '1')
			|| (map->grid[y][ft_linelen(map->grid[y]) - 1] != '1'))
			ft_free_Error(map, "Erro\nMapa não fechado.\n");
		y++;
	}
}

void	ft_check_elements(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->players = 0;
	map->coletaveis = 0;
	map->saida = 0;
	while (y < map->linhas)
	{
		x = 0;
		while (x < ft_linelen(map->grid[y]))
		{
			if (map->grid[y][x] == 'P')
				map->players++;
			if (map->grid[y][x] == 'C')
				map->coletaveis++;
			if (map->grid[y][x] == 'E')
				map->saida++;
			x++;
		}
		y++;
	}
	if (map->players != 1 || map->saida != 1 || map->coletaveis < 1)
		ft_free_Error(map, "Erro, mapa invalido\n");
}

void	ft_check_invalid_chars(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->linhas)
	{
		x = 0;
		while (x < ft_linelen(map->grid[y]))
		{
			if (!ft_isvalidchar(map->grid[y][x]))
				ft_free_Error(map, "Erro\nMapa Invalido.\n");
			x++;
		}
		y++;
	}
}

void	ft_check_playable(t_map *map)
{
	t_map	*cpy_map;

	cpy_map = ft_copymap(map);
	ft_floodfill(cpy_map, cpy_map->player_x, cpy_map->player_y);
	if (cpy_map->coletaveis != 0 || cpy_map->saida != 0)
		ft_free_Error(cpy_map, "Erro\nMapa não jogavel.\n");
	ft_free_map(cpy_map);
}
