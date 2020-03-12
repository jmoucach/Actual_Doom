/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:47:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/05 18:57:07 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void			ft_trace_line(t_point a, t_point b, t_fdf *img, int col)
{
	int			gap;
	int			ox;
	int			oy;
	SDL_Color	color;

	gap = img->map->base_gap;
	ox = img->map->ox;
	oy = img->map->oy;
	//color = ft_color_of_lower_element(a, b);
	color = ft_hexa_to_SDL(col);//fixed color until we adjust it
	SDL_SetRenderDrawColor(img->renderer, color.r, color.g, color.b,
			color.a);
	SDL_RenderDrawLine(img->renderer, ox + a.x * gap,
			oy + a.y * gap, ox + b.x * gap, oy + b.y * gap);
}

void			ft_print_grid(t_fdf *img, t_map *map)
{
	int			x;
	int			y;
	t_point		start;
	t_point		end;

	y = -1;
	while (++y <= map->y)
	{
		x = -1;
		while (++x <= map->x)
		{
			start.x = x;
			start.y = y;
			if (x <= map->x - 1)
			{
				end.x = x + 1;
				end.y = y;
				ft_trace_line(start, end, img, LIGHT_BLUE);
			}
			if (y <= map->y - 1)
			{
				end.x = x;
				end.y = y + 1;
				ft_trace_line(start, end, img, LIGHT_BLUE);
			}
		}
	}
}
