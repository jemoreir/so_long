/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:57:29 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 12:57:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "minilibx-linux/mlx.h"

typedef struct s_map
{
    char	**grid;
    int		linhas;
    int		colunas;
    int		player_x;
    int		player_y;
    int		coletaveis;
    int		saida;
    int		players;
}   t_map;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   map;
    int     moves;
}	t_game;

//void	read_map(char *path, t_map *map);
//void	check_map(t_map *map);
void	ft_free_map(t_map *map);
void	ft_exit_game(t_game *game, char *message);
void	ft_check_playable(t_map *map);
void	ft_check_invalid_chars(t_map *map);
void	ft_check_elements(t_map *map);
void	ft_check_walls(t_map *map);
void	ft_check_retangular(t_map *map);

#endif