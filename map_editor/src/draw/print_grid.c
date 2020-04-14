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

#include "../../hdr/map_editor.h"

void			ft_print_grid(t_fdf *img)
{
	int			x;
	int			y;
	t_pt		start;
	t_pt		end;

	/* Function as it was before
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
	}*/
	y = -1;
	/*DEBUG
	ft_putendl("img->map->x");
	ft_putnbr(img->map->x);
	ft_putendl("img->map->y");
	ft_putnbr(img->map->y);
	ft_putendl("okAA");*/
	while (++y < img->map->y)
	{
		start.x = 0;
		start.y = y;
		end.x = img->map->x;
		end.y = y;
		ft_trace_line(start, end, img, LIGHT_BLUE);
		//check_and_draw_line(start, end, img);
		/*if (end.x >= 0 && end.y >= 0 && start.x >= 0 && start.y >= 0)
			draw_line(start, end, img->pixels, LIGHT_BLUE);*/
	}
	x = -1;
	while (++x <= img->map->x)
	{
		start.x = x;
		start.y = 0;
		end.x = x;
		end.y = img->map->y;
		ft_trace_line(start, end, img, LIGHT_BLUE);
		//check_and_draw_line(start, end, img);
		/*if (end.x >= 0 && end.y >= 0 && start.x >= 0 && start.y >= 0)
			draw_line(start, end, img->pixels, LIGHT_BLUE);*/
	}
}
