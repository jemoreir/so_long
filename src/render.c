/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:05:26 by jemoreir          #+#    #+#             */
/*   Updated: 2025/11/07 18:05:26 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_destroy(t_game *game, int n)
{
	if (game->map.coletaveis == 0 && game->saida_aberta == 0)
	{
		mlx_destroy_image(game->mlx, game->saida);
		game->saida = mlx_xpm_file_to_image(game->mlx, "Assets/ex.xpm", &n, &n);
		game->saida_aberta = 1;
	}
}

void	ft_draw_map(t_game *g, int n)
{
	int	y;
	int	x;

	y = 0;
	ft_destroy(g, n);
	while (y < g->map.linhas)
	{
		x = 0;
		while (x < ft_linelen(g->map.grid[y]))
		{
			mlx_put_image_to_window(g->mlx, g->win, g->piso, x * n, y * n);
			if (g->map.grid[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->par, x * n, y * n);
			else if (g->map.grid[y][x] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->pl, x * n, y * n);
			else if (g->map.grid[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->col, x * n, y * n);
			else if (g->map.grid[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->saida, x * n, y * n);
			x++;
		}
		y++;
	}
}

void	ft_init_game(t_game *g, int n)
{
	g->col = mlx_xpm_file_to_image(g->mlx, "Assets/col.xpm", &n, &n);
	if (!g->col)
		ft_exit_game(g, "Erro ao carregar Assets/col.xpm\n");
	g->par = mlx_xpm_file_to_image(g->mlx, "Assets/par.xpm", &n, &n);
	if (!g->par)
		ft_exit_game(g, "Erro ao carregar Assets/par.xpm\n");
	g->pl = mlx_xpm_file_to_image(g->mlx, "Assets/pl.xpm", &n, &n);
	if (!g->pl)
		ft_exit_game(g, "Erro ao carregar Assets/pl.xpm\n");
	g->piso = mlx_xpm_file_to_image(g->mlx, "Assets/piso.xpm", &n, &n);
	if (!g->piso)
		ft_exit_game(g, "Erro ao carregar Assets/piso.xpm\n");
	g->saida = mlx_xpm_file_to_image(g->mlx, "Assets/portal.xpm", &n, &n);
	if (!g->saida)
		ft_exit_game(g, "Erro ao carregar Assets/portal.xpm\n");
	g->moves = 0;
	g->saida_aberta = 0;
	g->player_x = g->map.player_x;
	g->player_y = g->map.player_y;
}

void	ft_window(t_game *g, int *n)
{
	int	janela_x;
	int	janela_y;

	g->mlx = mlx_init();
	*n = 64;
	janela_x = *n * g->map.colunas;
	janela_y = *n * g->map.linhas;
	g->win = mlx_new_window(g->mlx, janela_x, janela_y, "so_long");
	if (!g->win)
		ft_exit_game(g, "Erro\nFalha em criar janela\n");
}
