/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:34:16 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/09 14:25:12 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void	ft_sub_fix_coords(t_map *map, int *x, int *y)
{
	int	tempx;
	int	tempy;
	int	crossx;
	int	crossy;
	float	decimalx;
	float	decimaly;

	tempx = *x - map->ox;
	tempy = *y - map->oy;
	crossx = tempx / map->base_gap;
	crossy = tempy / map->base_gap;
	decimalx = tempx % (int)map->base_gap;
	decimaly = tempy % (int)map->base_gap;
	*x = crossx; 
	*y = crossy; 
}

void	ft_fix_coords(t_map *map, int *x, int *y)
{
//	printf("original x = %d\n original y = %d\n ox = %d\n oy = %d\n endx = %d\n endy = %d\n", *x, *y, map->ox, map->oy, map->endx, map->endy);
	if (*x < map->ox)
		*x = map->ox;
	if (*y < map->oy)
		*y = map->oy;
	if (*x > map->endx)
		*x = map->endx;
	if (*y > map->endy)
		*y = map->endy;
	ft_sub_fix_coords(map, x, y);
}
