/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_appearance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:01:06 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/05 18:47:03 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void		ft_modify_height(int key, t_fdf *ptr)
{
	if (ptr->map->zmax < 100)
	{
		if (key == 12 && ptr->map->proj == 'I')
			ptr->map->base_h += 1;
		if (key == 6 && ptr->map->proj == 'I')
			ptr->map->base_h -= 1;
	}
	else
	{
		if (key == 12 && ptr->map->proj == 'I')
			ptr->map->base_h += 0.1;
		if (key == 6 && ptr->map->proj == 'I')
			ptr->map->base_h -= 0.1;
	}
}

void		ft_zoom(t_key *key, t_map *map)
{
	if (key->zoom_in == 1)
		map->base_gap += 1;
	if (key->zoom_out == 1)
	{
		if (map->base_gap >= 1)
			map->base_gap -= 1;
	}
}

void		ft_move(t_key *key, t_map *map)
{
	if (key->up == 1)
		map->oy -= 3;
	if (key->down == 1)
		map->oy += 3;
	if (key->left == 1)
		map->ox -= 3;
	if (key->right == 1)
		map->ox += 3;
}

/*
void		ft_iso_or_cart(int key, t_fdf *ptr)
{
	int		i;
	int		j;
	t_point	iso;

	if (key == 8 && ptr->map->proj == 'I')
	{
		i = -1;
		while (++i < ptr->map->y)
		{
			j = -1;
			while (++j < ptr->map->x)
			{
				iso = ptr->map->map[i][j];
				ptr->map->map[i][j].x = iso.y + iso.x / 2;
				ptr->map->map[i][j].y = iso.y - iso.x / 2;
			}
		}
		ptr->map->proj = 'C';
	}
	if (key == 34 && ptr->map->proj == 'C')
		ft_cart_to_iso(ptr->map);
}

void		ft_positive_or_negative(int key, t_fdf *ptr)
{
	if (key == 35)
		ptr->color = 'P';
	if (key == 45)
		ptr->color = 'N';
}*/
