/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:04:44 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/11 11:01:02 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void			click_to_modify_map(t_map *map, t_mouse *mous, SDL_Event e)
{
	int			x;
	int			y;

	SDL_GetMouseState(&(mous->click1[0]), &(mous->click1[1]));
	x = mous->click1[0];
	y = mous->click1[1];
	if (x > (WIDTH - 300) && x < (WIDTH - 30)) //avoids to listen for click on menu
		return ;
	ft_fix_coords(map, &x, &y);
	if ((y == 0 || x == 0 || y == map->y - 1 || x == map->x - 1) && mous->loop == 0)
		return ;
	if (y <= (map->y - 1) && x <= (map->x - 1))
		map->map[y][x] = mous->loop;
}
