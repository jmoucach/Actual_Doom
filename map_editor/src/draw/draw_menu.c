/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:41:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 17:15:26 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_rectangle(SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_RenderDrawLine(ren, x, y, x + w, y);
	SDL_RenderDrawLine(ren, x, y + h, x + w, y + h);
	SDL_RenderDrawLine(ren, x, y, x, y + h);
	SDL_RenderDrawLine(ren, x + w, y, x + w, y + h);
}

void			print_button_add_and_substract(t_fdf *img)
{
	int	i;

	i = 0;
	SDL_SetRenderDrawColor(img->renderer, 215, 0, 0, 0);
	while (++i < 60)
	{
		SDL_RenderDrawLine(img->renderer, 1321, 780 + i, 1320 + 230, 780 + i);
	}

	SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	SDL_RenderDrawLine(img->renderer, 1320 + 90, 810, 1320 + 230 - 90, 810);
	SDL_RenderDrawLine(img->renderer, 1320 + 90, 811, 1320 + 230 - 90, 811);
	SDL_RenderDrawLine(img->renderer, 1320 + 90, 809, 1320 + 230 - 90, 809);

	SDL_RenderDrawLine(img->renderer, 1320, 360 + 80, 1320 + 230, 360 + 80);
	SDL_RenderDrawLine(img->renderer, 1320, 360 + 79, 1320 + 230, 360 + 79);
	SDL_RenderDrawLine(img->renderer, 1320, 360 + 81, 1320 + 230, 360 + 81);
}
void			draw_textures_squares(t_fdf *img)
{
	int			i;

	SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	i = 0;
	while (++i <= 19)
	{
		ft_print_blocks(1320 + (((i - 1) % 3) * 80), 120 + (((i - 1) / 3) * 80), i, img, 70);
		ft_print_rectangle(img->renderer, 1320 + (((i - 1) % 3) * 80), 120 + (((i  -1 ) / 3) * 80), 70, 70);
	}
}

void			ft_render_buttons(t_fdf *img)
{
	SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	ft_print_rectangle(img->renderer, 1320, 280 + 500, 230, 60);//rem wall
	ft_print_rectangle(img->renderer, 1320, 360 + 500, 230, 60);//save wall
	draw_textures_squares(img);
	print_button_add_and_substract(img);
}

void			ft_print_pressed_button(t_fdf *img, int i)
{
	int			startx;
	int			starty;

	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	if (i == 0)
	{
		ft_print_rectangle(img->renderer, 1319, 279 + 500, 232, 62);
		ft_print_rectangle(img->renderer, 1318, 278 + 500, 234, 64);
	}
	else
	{
		startx = 1320 + (((i - 1) % 3) * 80);
		starty = 120 + (((i - 1) / 3) * 80);
		ft_print_rectangle(img->renderer, startx - 1, starty - 1, 72, 72);
		ft_print_rectangle(img->renderer, startx - 2, starty - 1, 74, 74);
	}
}
