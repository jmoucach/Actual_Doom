/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:49:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 14:34:43 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void			ft_print_menu_background(t_fdf *img)
{
	SDL_Color	color;
	int		i;

	i = -1;
	color = ft_hexa_to_SDL(0x2E2E2E);
	SDL_SetRenderDrawColor(img->renderer, color.r, color.g, color.b,
			color.a);
	while (++i < 270)
	{
		SDL_RenderDrawLine(img->renderer, (WIDTH - 300) + i, 0, (WIDTH - 300) + i, HEIGHT);
	}
}

void			ft_render_text(t_fdf *img)//SEGFAULT WHEN USED
{
	int			txt_w;
	int			txt_h;
	SDL_RenderCopy(img->renderer, img->txt->menu->texture, NULL,
			&img->txt->menu->rect);
	SDL_RenderCopy(img->renderer, img->txt->item->texture, NULL,
			&img->txt->item->rect);
}

void			ft_clear_and_render(t_fdf *img, int	loop)
{
	//ft_print_obj(img, olst);
	ft_render_buttons(img);
	ft_parse_and_print_textures(img);
	ft_print_grid(img, img->map);
	ft_print_menu_background(img);
	ft_render_buttons(img);
	ft_print_pressed_button(img, loop);
//	ft_render_text(img);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
	SDL_RenderClear(img->renderer);
}

void			ft_clear_and_render_menu(t_fdf *img)
{
//	ft_print_obj(img, olst);
	ft_render_buttons(img);
	ft_print_grid(img, img->map);
	ft_parse_and_print_textures(img);
//	ft_render_text(img);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
	SDL_RenderClear(img->renderer);
}
