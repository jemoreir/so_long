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
	return ;
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