/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:07:10 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:07:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			handle_input2(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_M])
	{
		data->menu = 1;
		free_objects(data);
	}
	if (state[SDL_SCANCODE_KP_PLUS])
		if (data->mouse_sens < 2.0)
			data->mouse_sens += 0.1;
	if (state[SDL_SCANCODE_KP_MINUS])
		if (data->mouse_sens > 0.5)
			data->mouse_sens -= 0.1;
	if (state[SDL_SCANCODE_O])
	{
		data->shaded = data->shaded == 1 ? 0 : 1;
		//TODO by default in parsing, remove when done
	}
	if (state[SDL_SCANCODE_E])
		check_doors(data);
}

void			handle_input(t_data *data, const Uint8 *state)
{
	SDL_GetRelativeMouseState(&(data->mouse.x), &(data->mouse.y));
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S])
		walk(data, state[SDL_SCANCODE_W] - state[SDL_SCANCODE_S],
				state[SDL_SCANCODE_LSHIFT]);
	if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_A])
		strafe(data, state[SDL_SCANCODE_D] - state[SDL_SCANCODE_A],
				state[SDL_SCANCODE_LSHIFT]);
	rotate(data);
	look_up_down(data);
	handle_input2(data, state);
}

void			game_loop(t_data *data)
{
	const Uint8	*state;
	int			width;
	SDL_Event	e;

	width = SCREEN_WIDTH;
	while (!data->quit)
	{
		data->time = SDL_GetTicks();
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				clean_exit(data, NULL);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
					data->p.is_firing = 1;
				else if (e.button.button == SDL_BUTTON_RIGHT)
				{
					if (data->p.swap_weapon == 1)
						data->p.selected_weapon = (data->p.selected_weapon + 1) % 7;
				}
			}
			if (e.type == SDL_MOUSEBUTTONUP)
				if (e.button.button == SDL_BUTTON_LEFT)
					data->p.is_firing = 0;
		}
		if (data->menu)
			menu(data);
		else
		{
			if (!SDL_GetKeyboardState(NULL)[SDL_SCANCODE_C])
				print_skybox(data);
			raycasting(data);
			state_machine(data);
			item_pickup(data);
			combat(data);
			if (data->toggle_minimap)
				draw_minimap(data);
		}
		data->ftime = (SDL_GetTicks() - data->time) / 1000;
		// printf("ftime :%f , fps:%f\n", data->ftime, 1/data->ftime);
		SDL_PumpEvents();
		state = SDL_GetKeyboardState(NULL);
		if (data->menu)
			handle_menu_input(data, state);
		else
			handle_input(data, state);
		red_hit_screen(data);
		green_hp_screen(data);
		blue_hp_screen(data);
		display_hud_keys(data);
		SDL_UpdateTexture(data->texture, NULL, data->pixels,
				width * 4);
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		if (!data->menu)
		{
			display_hud(data);
			display_health(data);
			display_ammo_side(data);
		}
		if (data->p.hp <= 0)
			clean_exit(data, "You are dead");
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		// SDL_Delay(5000);
	}
}
