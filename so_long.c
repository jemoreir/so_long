/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:13:39 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 13:13:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
	{
		write(2, "Argumentos Invalidos\n", 21);
		return (1);
	}
	map = load(argv[1]);
	if(!map)
		return(1);
	ft_check_map(map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->colunas * 32), (map->linhas * 32), "so_long");
	if(!game->win)
		ft_free_Error(map, "Erro\nFalha em criar janela\n");
	return (0);
}
