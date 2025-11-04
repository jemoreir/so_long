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
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

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
    void	*parede_image;
	void	*piso_image;
	void	*personagem_image;
	void	*saida_image;
	void	*coletavel_image;
    int		player_x;
	int		player_y;
    int		saida_aberta;
}	t_game;

void	ft_free_Error(t_map *map, char *erro);
void	ft_free_map(t_map *map);
void	ft_exit_game(t_game *game, char *message);
void	ft_check_playable(t_map *map);
void	ft_check_invalid_chars(t_map *map);
void	ft_check_elements(t_map *map);
void	ft_check_walls(t_map *map);
void	ft_check_retangular(t_map *map);
int		count_line(char *file);
char	**count_large(char *file);
void	find_player(t_map *map);
void	ft_check_map(t_map *map);
void	ft_init_map(t_map *map);
t_map	*load(char *file);
int		ft_linelen(char *line);
int		ft_check_line(char *line, t_map *map);
int     ft_isvalidchar(char c);
void    ft_floodfill(t_map *map, int x, int y);
t_map	*ft_copy(t_map *map);
t_map	*ft_copymap(t_map *map);
void	ft_draw_map(t_game *game, int size);
void	ft_init_game(t_game *game, int size);
void	ft_window(t_game *game, int *size);
void	ft_move_player(t_game *game, int dx, int dy);
int		ft_key_press(int keycode, t_game *game);
int		ft_close(t_game *game);

#endif