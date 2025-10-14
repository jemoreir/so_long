/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:07:05 by marvin            #+#    #+#             */
/*   Updated: 2025/10/14 15:07:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_map *map)
{
	ft_check_retangular(map);
	ft_check_walls(map);
	ft_check_elements(map);
	ft_check_invalid_chars(map);
	ft_check_playable(map);
	return ;
}