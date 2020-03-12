/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:38:39 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/04 11:41:02 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void				display_bullets_side(t_data *data)
{
	static short	old_bullets = MAX_BULLETS;
	SDL_Surface		*tmp;
	int				w;
	int				h;
	SDL_Rect		rect;

	tmp = NULL;
	if (data->p.bullets != old_bullets)
	{
		old_bullets = data->p.bullets;
		SDL_DestroyTexture(data->hud.bullets_text);
		tmp = TTF_RenderText_Solid(data->hud.font,
			ft_itoa(data->p.bullets), data->hud.text_color);
		data->hud.bullets_text = SDL_CreateTextureFromSurface(data->renderer,
			tmp);
		SDL_FreeSurface(tmp);
	}
	SDL_QueryTexture(data->hud.bullets_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 290 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 22, w / 2, h / 2};
	SDL_RenderCopy(data->renderer, data->hud.bullets_text, NULL, &rect);
}

void				display_shells_side(t_data *data)
{
	static short	old_shells = MAX_SHELLS;
	SDL_Surface		*tmp;
	int				w;
	int				h;
	SDL_Rect		rect;

	tmp = NULL;
	if (data->p.shells != old_shells)
	{
		old_shells = data->p.shells;
		SDL_DestroyTexture(data->hud.shells_text);
		tmp = TTF_RenderText_Solid(data->hud.font,
			ft_itoa(data->p.shells), data->hud.text_color);
		data->hud.shells_text = SDL_CreateTextureFromSurface(data->renderer,
			tmp);
		SDL_FreeSurface(tmp);
	}
	SDL_QueryTexture(data->hud.shells_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 290 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 50, w / 2, h / 2};
	SDL_RenderCopy(data->renderer, data->hud.shells_text, NULL, &rect);
}

void				display_cells_side(t_data *data)
{
	static short	old_cells = MAX_CELLS;
	SDL_Surface		*tmp;
	int				w;
	int				h;
	SDL_Rect		rect;

	if (data->p.cells != old_cells)
	{
		old_cells = data->p.cells;
		SDL_DestroyTexture(data->hud.cells_text);
		tmp = TTF_RenderText_Solid(data->hud.font,
			ft_itoa(data->p.cells), data->hud.text_color);
		data->hud.cells_text = SDL_CreateTextureFromSurface(data->renderer,
			tmp);
		SDL_FreeSurface(tmp);
	}
	SDL_QueryTexture(data->hud.cells_text, NULL, NULL, &w, &h);
	rect = (SDL_Rect){SCREEN_WIDTH * 290 / 320 - w / 2,
		SCREEN_HEIGHT * 0.8 + 105, w / 2, h / 2};
	SDL_RenderCopy(data->renderer, data->hud.cells_text, NULL, &rect);
}

void				display_current_ammo(t_data *data, short id)
{
	SDL_Rect		rect;
	int				w;
	int				h;

	if (id == 0 || id == 3)
	{
		data->hud.ammo_text = data->hud.infinite_text;
		w = 120;
		h = 60;
		rect = (SDL_Rect){SCREEN_WIDTH * 24 / 320 - w / 2,
			SCREEN_HEIGHT * 0.8 + 14, w, h};
	}
	else
	{
		if (id == 1)
			data->hud.ammo_text = data->hud.shells_text;
		else if (id == 2 || id == 5)
			data->hud.ammo_text = data->hud.cells_text;
		else if (id == 4 || id == 6)
			data->hud.ammo_text = data->hud.bullets_text;
		SDL_QueryTexture(data->hud.ammo_text, NULL, NULL, &w, &h);
		rect = (SDL_Rect){SCREEN_WIDTH * 27 / 320 - w / 2,
			SCREEN_HEIGHT * 0.8 + 14, w, h};
	}
	SDL_RenderCopy(data->renderer, data->hud.ammo_text, NULL, &rect);
}

void				display_ammo_side(t_data *data)
{
	display_bullets_side(data);
	display_shells_side(data);
	display_cells_side(data);
	display_current_ammo(data, data->p.selected_weapon);
}
