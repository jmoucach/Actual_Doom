/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:06:14 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:15:53 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void			ft_print_blocks(int x, int y, int map_value, t_fdf *img, int size)
{
	SDL_Rect	rect;
	SDL_Texture	*texture;

	rect = (SDL_Rect){x + 1, y + 1, size - 2, size - 2};
	texture = img->texture[map_value];
	/*if (rect == NULL || texture == NULL)
		ft_clean_exit(img, "Could not print blocks");*/
	SDL_RenderCopy(img->renderer, texture, NULL, &rect);
}

void			print_buttons_delete_and_save(t_fdf *img)
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

void			draw_menu_textures(t_fdf *img)
{
	int			i;

	i = 0;
	while (++i <= 18)
	{
		if (i == 12)
			i++;
		ft_print_blocks(1320 + (((i - 1) % 3) * 80), 120 + (((i - 1) / 3) * 80), i, img, 70);
	}
	print_buttons_delete_and_save(img);
}

void			ft_parse_and_print_textures(t_fdf *img)
{
	int			x;
	int			y;
	int			posx;
	int			posy;

	y = -1;
	while (++y < img->map->y)
	{
		x = -1;
		while (++x < img->map->x)
		{
			posy = (y * img->map->base_gap) + img->map->oy;
			posx = (x * img->map->base_gap) + img->map->ox;
			ft_print_blocks(posx, posy, img->map->map[y][x], img, img->map->base_gap);
		}
	}
}
