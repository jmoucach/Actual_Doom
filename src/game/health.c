/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:44:16 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 16:35:39 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void				display_armor(t_data *data)
{
	static short	old_armor = 100;
	SDL_Surface		*tmp;
	int				w;
	int				h;
	SDL_Rect		rect;

	if (data->p.armor != old_armor)
	{
		old_armor = data->p.armor;
		SDL_DestroyTexture(data->hud.armor_text);
		tmp = TTF_RenderText_Solid(data->hud.font,
			ft_itoa(data->p.armor), data->hud.text_color);
		data->hud.armor_text = SDL_CreateTextureFromSurface(data->renderer,
																		tmp);
		SDL_FreeSurface(tmp);
	}
	SDL_QueryTexture(data->hud.armor_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 208 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 10, w, h};
	SDL_RenderCopy(data->renderer, data->hud.armor_text, NULL, &rect);
}

void				display_health(t_data *data)
{
	static short	old_hp = 100;
	SDL_Surface		*tmp;
	int				w;
	int				h;
	SDL_Rect		rect;

	if (data->p.hp != old_hp)
	{
		old_hp = data->p.hp;
		SDL_DestroyTexture(data->hud.hp_text);
		tmp = TTF_RenderText_Solid(data->hud.font,
			ft_itoa(data->p.hp), data->hud.text_color);
		data->hud.hp_text = SDL_CreateTextureFromSurface(data->renderer, tmp);
		SDL_FreeSurface(tmp);
	}
	SDL_QueryTexture(data->hud.hp_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 74 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 10, w, h};
	SDL_RenderCopy(data->renderer, data->hud.hp_text, NULL, &rect);
	display_armor(data);
}
