/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/03/10 17:10:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			set_mous_loop(t_mouse *mous, int i)
{
	if (i == 12)
		return ;
	mous->loop = i;
//	loop_til_release();
}

void			ft_menu_event(/*t_map *map, */t_mouse *mous, SDL_Event e)
{
	int			tmx;
	int			tmy;
	int			x;
	int			y;
	int			i;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&tmx, &tmy);
			if (tmx >= 1320 && tmx <= 1560 && tmy >= 120 && tmy <= 600)
			{
				x = (tmx - 1320) / 80;
				y = (tmy - 120) / 80;
				i = y * 3 + x + 1;
				set_mous_loop(mous, i);
			}
			if (tmx >= 1320 && tmx <= (1320 + 230) && tmy >= (280 + 500) && tmy <= (280 + 560))
				set_mous_loop(mous, 0);
			if (tmx >= 1320 && tmx <= (1320 + 230) && tmy >= (360 + 500) && tmy <= (360 + 560))
				set_mous_loop(mous, -1);
		}
	}
}
