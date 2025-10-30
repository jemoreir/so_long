/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:07:05 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 15:07:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_map *map)
{
	ft_check_retangular(map);
	ft_check_walls(map);
	ft_check_elements(map);
	ft_check_invalid_chars(map);
	ft_check_playable(map);
}

int	ft_check_line(char *line, t_map *map)
{
	int	i;

	i = 0;
	while(i < ft_linelen(line))
	{
		if(line[i] != '1')
		{
			ft_free_Error(map, "Error\nMapa não fechado.\n");
			return(1);
		}
		i++;
	}
	return(0);
}

int	ft_isvalidchar(char c)
{
	if(c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	else
		return (0);
}

void	ft_init_map(t_map *map)
{
	map->grid = NULL;
	map->linhas = 0;
	map->colunas = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->saida = 0;
	map->coletaveis = 0;
	map->players = 0;
}

t_map	*ft_copymap(t_map *map)
{
	int	y;
	t_map	*cpy_map;

	cpy_map = ft_copy(map);
	if(!cpy_map)
		return(NULL);
	y = 0;
	if(cpy_map->linhas != map->linhas)
		ft_free_Error(cpy_map, "linhas invalidas.");
	cpy_map->grid = malloc(sizeof (char *) * (cpy_map->linhas + 1));
	if(!cpy_map->grid)
		ft_free_Error(cpy_map, NULL);
	while(y < cpy_map->linhas)
	{
		cpy_map->grid[y] = malloc(ft_linelen(map->grid[y]) + 1);
		if(!cpy_map->grid[y])
			ft_free_Error(cpy_map, NULL);
		ft_strlcpy(cpy_map->grid[y], map->grid[y], (ft_linelen(map->grid[y]) + 1));
		y++;
	}
	cpy_map->grid[y] = NULL;
	return(cpy_map);
}
