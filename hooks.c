/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:07:07 by marvin            #+#    #+#             */
/*   Updated: 2025/11/04 16:07:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player_x + dx;
	ny = game->player_y + dy;
	if(game->map.grid[ny][nx] == '1')
		return;
	if (game->map.grid[ny][nx] == 'E' && game->map.coletaveis != 0)
		return;
	if(game->map.grid[ny][nx] == 'C')
		game->map.coletaveis--;
	if(game->map.grid[ny][nx] == 'E' && game->map.coletaveis == 0)
		ft_exit_game(game, "Vitoria\n");
	game->map.grid[ny][nx] = 'P';
	game->map.grid[game->player_y][game->player_x] = '0';
	game->player_x = nx;
	game->player_y = ny;
	game->moves++;
	ft_printf("Movimentos: %d\n", game->moves);
	ft_draw_map(game, 64);
}

int	ft_key_press(int keycode, t_game *game)
{
	if(keycode == 65307)
		ft_exit_game(game, NULL);
	else if(keycode == 119)
		ft_move_player(game, 0, -1);
	else if(keycode == 115)
		ft_move_player(game, 0, 1);
	else if (keycode == 97)
		ft_move_player(game, -1, 0);
	else if (keycode == 100)
		ft_move_player(game, 1, 0);
	return (0);
}
