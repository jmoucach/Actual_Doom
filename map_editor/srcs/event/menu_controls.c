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

#include "../../map_editor.h"

void			set_mous_loop(t_mouse *mous, int i)
{
	mous->loop = i;
	loop_til_release();
}

void			ft_menu_event(t_map *map, t_mouse *mous, SDL_Event e)
{
	int			tmx;
	int			tmy;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&tmx, &tmy);
			if (tmx >= 1320 && tmx <= (1320 + 70) && tmy >= 120 && tmy <= 190)
				set_mous_loop(mous, 1);
			if (tmx >= 1400 && tmx <= (1400 + 70) && tmy >= 120 && tmy <= 190)
				set_mous_loop(mous, 2);
			if (tmx >= 1480 && tmx <= (1480 + 70) && tmy >= 120 && tmy <= 190)
				set_mous_loop(mous, 3);

			if (tmx >= 1320 && tmx <= (1320 + 70) && tmy >= 200 && tmy <= 200 + 70)
				set_mous_loop(mous, 4);
			if (tmx >= 1400 && tmx <= (1400 + 70) && tmy >= 200 && tmy <= 200 + 70)
				set_mous_loop(mous, 5);
			if (tmx >= 1480 && tmx <= (1480 + 70) && tmy >= 200 && tmy <= 200 + 70)
				set_mous_loop(mous, 6);
			if (tmx >= 1320 && tmx <= (1320 + 70) && tmy >= 280 && tmy <= 280 + 70)
				set_mous_loop(mous, 7);
			if (tmx >= 1400 && tmx <= (1400 + 70) && tmy >= 280 && tmy <= 280 + 70)
				set_mous_loop(mous, 8);

			if (tmx >= 1320 && tmx <= (1320 + 70) && tmy >= 450 && tmy <= 450 + 70)
				set_mous_loop(mous, 9);
			if (tmx >= 1400 && tmx <= (1400 + 70) && tmy >= 450 && tmy <= 450 + 70)
				set_mous_loop(mous, 10);
			if (tmx >= 1480 && tmx <= (1480 + 70) && tmy >= 450 && tmy <= 450 + 70)
				set_mous_loop(mous, 11);
			if (tmx >= 1320 && tmx <= (1320 + 70) && tmy >= 530 && tmy <= 530 + 70)
				set_mous_loop(mous, 12);
			if (tmx >= 1320 && tmx <= (1320 + 230) && tmy >= (280 + 500) && tmy <= (280 + 560))
				set_mous_loop(mous, 0);
			if (tmx >= 1320 && tmx <= (1320 + 230) && tmy >= (360 + 500) && tmy <= (360 + 560))
				set_mous_loop(mous, -1);
			//every if checks if you click on every button and if you do it runs wall placing button, objects and enemy placing 
			//or undo/remove/move elements
		}
	}
}
