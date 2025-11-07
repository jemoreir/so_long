/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:05:32 by jemoreir          #+#    #+#             */
/*   Updated: 2025/11/07 18:05:32 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_ber(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5)
		return (0);
	if (name[len - 4] == '.' && name[len - 3] == 'b'
		&& name[len - 2] == 'e' && name[len - 1] == 'r')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;
	int		size;

	if (argc != 2 || !ft_is_ber(argv[1]))
	{
		ft_putstr_fd("Argumentos Invalidos\nUse um arquivo .ber", 2);
		return (1);
	}
	map = load(argv[1]);
	if (!map)
		return (1);
	ft_check_map(map);
	game.map = *map;
	ft_window(&game, &size);
	ft_init_game(&game, size);
	ft_draw_map(&game, size);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
