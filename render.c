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

void	ft_draw_map(t_game *game, int size)
{
	int	y;
	int	x;

	y = 0;
	while(y < game->map.linhas)
	{
		if (game->map.coletaveis == 0 && game->saida_aberta == 0)
			game->saida_image = mlx_xpm_file_to_image(game->mlx, "Assets/portal2.xpm", &size, &size);
		x = 0;
		while(x < ft_linelen(game->map.grid[y]))
		{
			mlx_put_image_to_window(game->mlx, game->win, game->piso_image, (x * size), (y * size));
			if(game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->parede_image, (x * size), (y * size));
			else if(game->map.grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->personagem_image, (x * size), (y * size));
			else if(game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coletavel_image, (x * size), (y * size));
			else if(game->map.grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->saida_image, (x * size), (y * size));
			x++;
		}
		y++;
	}
}

void	ft_init_game(t_game *game, int size)
{
	game->coletavel_image = mlx_xpm_file_to_image(game->mlx, "Assets/coletavel.xpm", &size, &size);
	ft_printf("coletavel %dx%d", size, size);
	if(!game->coletavel_image)
		ft_exit_game(game, "Erro ao carregar Assets/coletavel.xpm\n");
	game->parede_image = mlx_xpm_file_to_image(game->mlx, "Assets/parede.xpm", &size, &size);
	ft_printf("parede %dx%d", size, size);
	if(!game->parede_image)
		ft_exit_game(game, "Erro ao carregar Assets/parede.xpm\n");
	game->personagem_image = mlx_xpm_file_to_image(game->mlx, "Assets/personagem.xpm", &size, &size);
	ft_printf("personagem %dx%d", size, size);
	if(!game->personagem_image)
		ft_exit_game(game, "Erro ao carregar Assets/personagem.xpm\n");
	game->piso_image = mlx_xpm_file_to_image(game->mlx, "Assets/piso.xpm", &size, &size);
	ft_printf("piso %dx%d", size, size);
	if(!game->piso_image)
		ft_exit_game(game, "Erro ao carregar Assets/piso.xpm\n");
	game->saida_image = mlx_xpm_file_to_image(game->mlx, "Assets/portal.xpm", &size, &size);
	ft_printf("saida %dx%d", size, size);
	if(!game->saida_image)
		ft_exit_game(game, "Erro ao carregar Assets/portal.xpm\n");
	game->moves = 0;
	game->saida_aberta = 0;
	game->player_x = game->map.player_x;
	game->player_y = game->map.player_y;
}

void	ft_window(t_game *game, int *size)
{
	int	janela_x;
	int	janela_y;

	game->mlx = mlx_init();
	*size = 64;
	janela_x = *size * game->map.colunas;
	janela_y = *size * game->map.linhas;
	game->win = mlx_new_window(game->mlx, janela_x, janela_y, "so_long");
	if(!game->win)
		ft_exit_game(game, "Erro\nFalha em criar janela\n");
}
