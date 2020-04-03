/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:10:12 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 14:54:12 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_infinite_loop(t_fdf *img, t_mouse *mous, t_key *key)
{
	int			isquit;
	SDL_Event	event;

	isquit = 0;
	while (isquit == 0)
	{
		//while (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
		SDL_PollEvent(&event);
//		while (SDL_PollEvent(&event))
//		{
			if (event.type == SDL_QUIT)
				exit (0);
			ft_menu_event( mous, event);
			//ft_print_pressed_button(img, mous->loop);
			ft_clear_and_render(img, mous->loop);
			ft_keys_event(img->map, event, key);
			ft_mouse_event(img, mous, event);
//		}
	}
}

void		ft_fdf(t_map *map, char *map_name)
{
	t_fdf	*img;
	t_mouse	mous;
	t_key	key;

	if (!(img = ft_ptr_init(map_name)))
		return ;
	if (!(ft_mouse_init(&mous)) || !(ft_key_init(&key)))
		return ;
	img->map = map;
	ft_clear_and_render(img, mous.loop);
	ft_infinite_loop(img, &mous, &key);
}
