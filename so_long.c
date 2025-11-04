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
	t_game	game;
	int		size;

	if (argc != 2)
	{
		write(2, "Argumentos Invalidos\n", 21);
		return (1);
	}
	map = load(argv[1]);
	if(!map)
		return(1);
	ft_printf("linhas: %d\ncolunas: %d\n", map->linhas, map->colunas);
	ft_check_map(map);
	game.map = *map;
	ft_window(&game, &size);
	ft_init_game(&game, size);
	ft_draw_map(&game, size);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_loop(game.mlx);
	return(0);
}
