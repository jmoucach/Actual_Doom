/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cart_to_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:22:31 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:44:23 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"
/*
void		ft_cart_to_iso(t_map *map)
{
	t_point	cart;
	int		i;
	int		j;

	i = -1;
	map->zmax = 0;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			cart = map->map[i][j];
			map->map[i][j].x = cart.x - cart.y;
			map->map[i][j].y = (cart.x + cart.y) / 2;
			if (map->map[i][j].z > map->zmax)
				map->zmax = map->map[i][j].z;
		}
	}
	map->proj = 'I';
}*/
