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
/*
int				ft_object_to_texture(int object)
{
	if (object == 'P')
		return (7);
	if (object == 'E')
		return (8);
	if (object == 'S')
		return (9);
	if (object == 'B')
		return (10);
	if (object == 'C')
		return (11);
	if (object == 'H')
		return (12);
	if (object == 'O')
		return (13);
	else
		return (0);
}
*/
void			ft_print_blocks(int x, int y, int map_value, t_fdf *img, int size)
{
	SDL_Rect	rect;
	SDL_Texture	*texture;
	
	rect = (SDL_Rect){x, y, size, size};
	texture = img->texture[map_value];
	SDL_RenderCopy(img->renderer, texture, NULL, &rect);
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
