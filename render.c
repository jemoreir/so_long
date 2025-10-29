/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:54:14 by marvin            #+#    #+#             */
/*   Updated: 2025/10/29 19:54:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_game *game, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while(y < map->linhas)
	{
		x = 0;
		while(x < ft_linelen(map->grid[y]))
		{

		}
	}
}

void	ft_init_game(t_game *game)
{
	int	size;

	size = 32;
	game->coletavel_image = mlx_xpm_file_to_image(game->mlx, "Assets/coletavel.xpm", &size, &size);
	if(!game->coletavel_image)
		ft_exit_game(game, "Erro ao carregar Assets/coletavel.xpm\n");
	game->parede_image = mlx_xpm_file_to_image(game->mlx, "Assets/parede.xpm", &size, &size);
	if(!game->parede_image)
		ft_exit_game(game, "Erro ao carregar Assets/parede.xpm\n");
	game->personagem_image = mlx_xpm_file_to_image(game->mlx, "Assets/personagem.xpm", &size, &size);
	if(!game->personagem_image)
		ft_exit_game(game, "Erro ao carregar Assets/personagem.xpm\n");
	game->piso_image = mlx_xpm_file_to_image(game->mlx, "Assets/piso.xpm", &size, &size);
	if(!game->piso_image)
		ft_exit_game(game, "Erro ao carregar Assets/piso.xpm\n");
	game->saida_image = mlx_xpm_file_to_image(game->mlx, "Assets/portal.xpm", &size, &size);
	if(!game->saida_image)
		ft_exit_game(game, "Erro ao carregar Assets/portal.xpm\n");
}
