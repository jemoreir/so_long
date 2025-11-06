/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:43:52 by marvin            #+#    #+#             */
/*   Updated: 2025/10/28 22:43:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->linhas || x >= ft_linelen(map->grid[0]))
		return ;
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'V')
		return ;
	if (map->grid[y][x] == 'C')
		map->coletaveis--;
	if (map->grid[y][x] == 'E')
		map->saida--;
	map->grid[y][x] = 'V';
	ft_floodfill(map, x + 1, y);
	ft_floodfill(map, x - 1, y);
	ft_floodfill(map, x, y + 1);
	ft_floodfill(map, x, y - 1);
}

t_map	*ft_copy(t_map *map)
{
	t_map	*cpy_map;

	cpy_map = malloc(sizeof (t_map));
	if (!cpy_map)
		return (NULL);
	cpy_map->linhas = map->linhas;
	cpy_map->colunas = map->colunas;
	cpy_map->player_x = map->player_x;
	cpy_map->player_y = map->player_y;
	cpy_map->coletaveis = map->coletaveis;
	cpy_map->saida = map->saida;
	cpy_map->grid = NULL;
	return (cpy_map);
}
