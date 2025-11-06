/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:58:41 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 14:58:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_error(t_map *map, char *erro)
{
	int	i;

	if (!map || !map->grid)
	{
		ft_putstr_fd("Erro\n map ou map->grid inexistente.", 2);
		exit(1);
	}
	i = 0;
	while (i < map->linhas)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	if (!erro)
		ft_putstr_fd("Erro ao alocar mapa\n", 2);
	else
		ft_putstr_fd(erro, 2);
	free(map->grid);
	free(map);
	exit(1);
}

void	ft_free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
	{
		ft_putstr_fd("Erro\n Mapa invalido free map.\n", 2);
		return ;
	}
	i = 0;
	while (i < map->linhas)
		free(map->grid[i++]);
	free(map->grid);
	map->grid = NULL;
}

void	ft_exit_game(t_game *game, char *mensagem)
{
	if (mensagem)
		write(2, mensagem, ft_strlen(mensagem));
	if (game->col)
		mlx_destroy_image(game->mlx, game->col);
	if (game->par)
		mlx_destroy_image(game->mlx, game->par);
	if (game->pl)
		mlx_destroy_image(game->mlx, game->pl);
	if (game->piso)
		mlx_destroy_image(game->mlx, game->piso);
	if (game->saida)
		mlx_destroy_image(game->mlx, game->saida);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_free_map(&game->map);
	exit(1);
}

int	ft_close(t_game *game)
{
	ft_exit_game(game, NULL);
	return (0);
}
