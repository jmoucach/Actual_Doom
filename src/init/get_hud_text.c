/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hud_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:25:39 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:27:04 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

static void	get_hud_text_2(t_data *data)
{
	SDL_Surface	*tmp;

	tmp = TTF_RenderText_Solid(data->hud.font, "INFINITE",
														data->hud.text_color);
	if (!(data->hud.infinite_text = SDL_CreateTextureFromSurface(data->renderer,
																		tmp)))
		clean_exit(data, (char*)SDL_GetError());
	SDL_FreeSurface(tmp);
	tmp = TTF_RenderText_Solid(data->hud.font, ft_itoa(data->p.cells),
														data->hud.text_color);
	if (!(data->hud.cells_text = SDL_CreateTextureFromSurface(data->renderer,
																		tmp)))
		clean_exit(data, (char*)SDL_GetError());
	SDL_FreeSurface(tmp);
}

void		get_hud_text_1(t_data *data)
{
	SDL_Surface	*tmp;

	tmp = TTF_RenderText_Solid(data->hud.font, ft_itoa(data->p.hp),
														data->hud.text_color);
	if (!(data->hud.hp_text = SDL_CreateTextureFromSurface(data->renderer,
																		tmp)))
		clean_exit(data, (char*)SDL_GetError());
	SDL_FreeSurface(tmp);
	tmp = TTF_RenderText_Solid(data->hud.font, ft_itoa(data->p.bullets),
														data->hud.text_color);
	if (!(data->hud.bullets_text = SDL_CreateTextureFromSurface(data->renderer,
																		tmp)))
		clean_exit(data, (char*)SDL_GetError());
	SDL_FreeSurface(tmp);
	tmp = TTF_RenderText_Solid(data->hud.font, ft_itoa(data->p.shells),
														data->hud.text_color);
	if (!(data->hud.shells_text = SDL_CreateTextureFromSurface(data->renderer,
																		tmp)))
		clean_exit(data, (char*)SDL_GetError());
	SDL_FreeSurface(tmp);
	get_hud_text_2(data);
}
