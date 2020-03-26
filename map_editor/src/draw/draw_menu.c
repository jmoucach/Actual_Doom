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
	while (++i <= 17)
	{
		ft_print_blocks(1320 + (((i - 1) % 3) * 80), 120 + (((i - 1) / 3) * 80), i, img, 70);
		ft_print_rectangle(img->renderer, 1320 + (((i - 1) % 3) * 80), 120 + (((i  -1 ) / 3) * 80), 70, 70);
	}/*
	while (++i <= 16)
	{
		ft_print_blocks(1320 + ((i  % 3) * 80), 130 + ((i / 3) * 80), i, img, 70);
		ft_print_rectangle(img->renderer, 1320 + ((i % 3) * 80), 130 + ((i / 3) * 80), 70, 70);
	}*/
		/*
	SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	ft_print_blocks(1320, 120, 1, img, 70);
	ft_print_rectangle(img->renderer, 1320, 120, 70, 70);
	ft_print_blocks(1400, 120, 2, img, 70);
	ft_print_rectangle(img->renderer, 1400, 120, 70, 70);
	ft_print_blocks(1480, 120, 3, img, 70);
	ft_print_rectangle(img->renderer, 1480, 120, 70, 70);
	ft_print_blocks(1320, 200, 4, img, 70);
	ft_print_rectangle(img->renderer, 1320, 200, 70, 70);
	ft_print_blocks(1400, 200, 5, img, 70);
	ft_print_rectangle(img->renderer, 1400, 200, 70, 70);
	ft_print_blocks(1480, 200, 6, img, 70);
	ft_print_rectangle(img->renderer, 1480, 200, 70, 70);
	ft_print_blocks(1320, 280, 7, img, 70);
	ft_print_rectangle(img->renderer, 1320, 280, 70, 70);
	ft_print_blocks(1400, 280, 8, img, 70);
	ft_print_rectangle(img->renderer, 1400, 280, 70, 70);
	ft_print_blocks(1480, 280, 9, img, 70);
	ft_print_rectangle(img->renderer, 1480, 280, 70, 70);
	ft_print_blocks(1320, 360, 10, img, 70);
	ft_print_rectangle(img->renderer, 1320, 360, 70, 70);
	ft_print_blocks(1400, 360, 11, img, 70);
	ft_print_rectangle(img->renderer, 1400, 360, 70, 70);

	ft_print_blocks(1320, 450, 12, img, 70);
	ft_print_rectangle(img->renderer, 1320, 450, 70, 70);
	ft_print_blocks(1400, 450, 13, img, 70);
	ft_print_rectangle(img->renderer, 1400, 450, 70, 70);
	ft_print_blocks(1480, 450, 14, img, 70);
	ft_print_rectangle(img->renderer, 1480, 450, 70, 70);
	ft_print_blocks(1320, 530, 15, img, 70);
	ft_print_rectangle(img->renderer, 1320, 530, 70, 70);
	ft_print_blocks(1320, 530, 167, img, 70);
	ft_print_rectangle(img->renderer, 1320, 530, 70, 70);*/
}

void			ft_render_buttons(t_fdf *img)
{ //fill_textures_squares(img);
	//draw_
	SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	ft_print_rectangle(img->renderer, 1320, 280 + 500, 230, 60);//rem wall
	ft_print_rectangle(img->renderer, 1320, 360 + 500, 230, 60);//save wall
	draw_textures_squares(img);
	print_button_add_and_substract(img);
}
/*
void			ft_render_buttons(t_fdf *img)
{
	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	ft_print_rectangle(img->renderer, 1320, 120, 230, 50);
	ft_print_rectangle(img->renderer, 1320, 180, 230, 50);
	ft_print_rectangle(img->renderer, 1320, 300, 115, 50);
	ft_print_rectangle(img->renderer, 1435, 300, 115, 50);
	ft_print_rectangle(img->renderer, 1320, 350, 115, 50);
	ft_print_rectangle(img->renderer, 1435, 350, 115, 50);
	SDL_SetRenderDrawColor(img->renderer, 255, 255, 0, 0);
	ft_print_rectangle(img->renderer, 1320, 240, 230, 50);
}*/

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
	/*
	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	if (i == 1)
	{
		ft_print_rectangle(img->renderer, 1320 - 1, 119, 72, 72);
		ft_print_rectangle(img->renderer, 1320 - 2, 118, 74, 74);
	}
	if (i == 2)
	{
		ft_print_rectangle(img->renderer, 1400 - 1, 119, 72, 72);
		ft_print_rectangle(img->renderer, 1400 - 2, 118, 74, 74);
	}
	if (i == 3)
	{
		ft_print_rectangle(img->renderer, 1480 - 1, 119, 72, 72);
		ft_print_rectangle(img->renderer, 1480 - 2, 118, 74, 74);
	}
	if (i == 4)
	{
		ft_print_rectangle(img->renderer, 1320 - 1, 199, 72, 72);
		ft_print_rectangle(img->renderer, 1320 - 2, 198, 74, 74);
	}
	if (i == 5)
	{
		ft_print_rectangle(img->renderer, 1400 - 1, 199, 72, 72);
		ft_print_rectangle(img->renderer, 1400 - 2, 198, 74, 74);
	}
	if (i == 6)
	{
		ft_print_rectangle(img->renderer, 1480 - 1, 199, 72, 72);
		ft_print_rectangle(img->renderer, 1480 - 2, 198, 74, 74);
	}
	if (i == 7)
	{
		ft_print_rectangle(img->renderer, 1320 - 1, 279, 72, 72);
		ft_print_rectangle(img->renderer, 1320 - 2, 278, 74, 74);
	}
	if (i == 8)
	{
		ft_print_rectangle(img->renderer, 1400 - 1, 279, 72, 72);
		ft_print_rectangle(img->renderer, 1400 - 2, 278, 74, 74);
	}
	if (i == 9)
	{
		ft_print_rectangle(img->renderer, 1320 - 1, 449, 72, 72);
		ft_print_rectangle(img->renderer, 1320 - 2, 448, 74, 74);
	}
	if (i == 10)
	{
		ft_print_rectangle(img->renderer, 1400 - 1, 449, 72, 72);
		ft_print_rectangle(img->renderer, 1400 - 2, 448, 74, 74);
	}
	if (i == 11)
	{
		ft_print_rectangle(img->renderer, 1480 - 1, 449, 72, 72);
		ft_print_rectangle(img->renderer, 1480 - 2, 448, 74, 74);
	}
	if (i == 12)
	{
		ft_print_rectangle(img->renderer, 1320 - 1, 529, 72, 72);
		ft_print_rectangle(img->renderer, 1320 - 2, 528, 74, 74);
	}
	if (i == 14)
	{
		ft_print_rectangle(img->renderer, 1480 - 1, 280 - 1, 72, 72);
		ft_print_rectangle(img->renderer, 1480 - 2, 280 - 2, 74, 74);
	}
	if (i == 15)
	{
		ft_print_rectangle(img->renderer, 1320 - 1, 360 - 1, 72, 72);
		ft_print_rectangle(img->renderer, 1320 - 2, 360 - 2, 74, 74);
	}
	if (i == 16)
	{
		ft_print_rectangle(img->renderer, 1400 - 1, 360 - 1, 72, 72);
		ft_print_rectangle(img->renderer, 1400 - 2, 360 - 2, 74, 74);
	}
	if (i == 0)
	{
		ft_print_rectangle(img->renderer, 1319, 279 + 500, 232, 62);
		ft_print_rectangle(img->renderer, 1318, 278 + 500, 234, 64);
	}*/
}
