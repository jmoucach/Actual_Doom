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

void			ft_print_rectangle(t_fdf *img, int x, int y, int w, int h)
{
	/*t_pt			pt_a;
	t_pt			pt_b;
	t_pt			pt_c;
	t_pt			pt_d;

	pt_a = coord_to_pt(x, y);
	pt_b = coord_to_pt(x + w, y);
	pt_c = coord_to_pt(x + w, y + h);
	pt_d = coord_to_pt(x, y + h);
	check_and_draw_line(pt_a, pt_b, img, WHITE);
	check_and_draw_line(pt_b, pt_c, img, WHITE);
	check_and_draw_line(pt_c, pt_d, img, WHITE);
	check_and_draw_line(pt_d, pt_a, img, WHITE);*/
	
	//WE NEED TO USE PREVIOUS FUNCTION BUT IT DOES NOT WORK ATM, SO TO BE FIXED
	SDL_SetRenderDrawColor(img->renderer, 255, 255, 255, 0);
	SDL_RenderDrawLine(img->renderer, x, y, x + w, y);
	SDL_RenderDrawLine(img->renderer, x, y + h, x + w, y + h);
	SDL_RenderDrawLine(img->renderer, x, y, x, y + h);
	SDL_RenderDrawLine(img->renderer, x + w, y, x + w, y + h);
	
}

void			print_button_add_and_substract(t_fdf *img)
{
	//WE COULD ALSO MODIFY THIS FUNCTION TO HAVE TEXTURED BUTTONS I/O JUST COLORS
	SDL_Rect	red_button;
	SDL_Rect	minus_bar;
	
	SDL_SetRenderDrawColor(img->renderer, 215, 0, 0, 0);
	red_button = (SDL_Rect){1321, 780, 230, 60};
	SDL_RenderFillRect(img->renderer, &red_button);
	SDL_SetRenderDrawColor(img->renderer, 255, 255, 255, 0);
	minus_bar = (SDL_Rect){1410, 810, 50, 3};
	SDL_RenderFillRect(img->renderer, &minus_bar);
}
void			draw_textures_squares(t_fdf *img)
{
	int			i;

	//SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	i = 0;
	while (++i <= 18)
	{
		if (i == 12)
			i++;
		ft_print_blocks(1320 + (((i - 1) % 3) * 80), 120 + (((i - 1) / 3) * 80), i, img, 70);
		ft_print_rectangle(img, 1320 + (((i - 1) % 3) * 80) - 1, 120 + (((i  - 1 ) / 3) * 80) - 1, 70 + 2, 70 + 2);
	}
}

void			ft_render_buttons(t_fdf *img)
{
	//SDL_SetRenderDrawColor(img->renderer, 215, 215, 215, 0);
	ft_print_rectangle(img, 1320 - 1, 280 + 500 - 1, 230 + 2, 60 + 2);//rem wall
	ft_print_rectangle(img, 1320 - 1, 360 + 500 - 1, 230 + 2, 60 + 2);//save wall
	print_button_add_and_substract(img);
	draw_textures_squares(img);
}

void			ft_print_pressed_button(t_fdf *img, int i)
{
	int			startx;
	int			starty;

	//SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	if (i == 12)
		return ;
	/*if (i == 0)//Seems that nothing changes when I (un)comment this
	{
		ft_print_rectangle(img, 1319, 279 + 500, 232, 62);
		ft_print_rectangle(img, 1318, 278 + 500, 234, 64);
	}
	else
	{
		startx = 1320 + (((i - 1) % 3) * 80);
		starty = 120 + (((i - 1) / 3) * 80);
		ft_print_rectangle(img, startx - 1, starty - 1, 72, 72);
		ft_print_rectangle(img, startx - 2, starty - 2, 74, 74);
	}*/
}
