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
	// t_game game;

	if (argc != 2)
	{
		write(2, "Argumentos Invalidos\n", 21);
		return (1);
	}
	// carregar o mapa com o read_map
	// checkar o mapa com check_map
	printf("Map: %s\n", argv[1]);
	return (0);
}