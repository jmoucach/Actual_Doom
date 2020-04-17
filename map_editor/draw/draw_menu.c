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
	t_pt			pt_a;
	t_pt			pt_b;
	t_pt			pt_c;
	t_pt			pt_d;

	pt_a = coord_to_pt(x, y);
	pt_b = coord_to_pt(x + w, y);
	pt_c = coord_to_pt(x + w, y + h);
	pt_d = coord_to_pt(x, y + h);
	draw_line(pt_a, pt_b, img->pixels, WHITE);
	draw_line(pt_b, pt_c, img->pixels, WHITE);
	draw_line(pt_c, pt_d, img->pixels, WHITE);
	draw_line(pt_d, pt_a, img->pixels, WHITE);
}


void			draw_menu_squares(t_fdf *img)
{
	int			i;

	i = 0;
	while (++i <= 18)
	{
		if (i == 12)
			i++;
		ft_print_rectangle(img, 1320 + (((i - 1) % 3) * 80) - 1, 120 + (((i  - 1 ) / 3) * 80) - 1, 70 + 2, 70 + 2);
	}
	ft_print_rectangle(img, 1320 - 1, 280 + 500 - 1, 230 + 2, 60 + 2);//rem wall
	ft_print_rectangle(img, 1320 - 1, 360 + 500 - 1, 230 + 2, 60 + 2);//save wall
}

void			ft_print_pressed_button(t_fdf *img, int i)
{
	int			startx;
	int			starty;

	if (i == 12)
		return ;
	if (i == 0)
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
	}
}