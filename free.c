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

void	ft_free_map(t_map *map, char *erro)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->linhas)
		free(map->grid[i++]);
	free(map->grid);
	ft_putstr_fd(erro, 2);
}

void	ft_exit_game(t_game *game, char *mensagem)
{
	if (mensagem)
		write(2, mensagem, strlen(mensagem));
	ft_free_map(&game->map, mensagem);
	exit(1);
}