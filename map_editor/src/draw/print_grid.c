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

	// Function as it was before
	/*y = -1;
	while (++y <= img->map->y)
	{
		x = -1;
		while (++x <= img->map->x)
		{
			start.x = x;
			start.y = y;
			if (x <= img->map->x - 1)
			{
				end.x = x + 1;
				end.y = y;
				ft_trace_line(start, end, img, LIGHT_BLUE);
			}
			if (y <= img->map->y - 1)
			{
				end.x = x;
				end.y = y + 1;
				ft_trace_line(start, end, img, LIGHT_BLUE);
			}
		}
	}
	*/
	y = -1;
	while (++y < img->map->y)
	{
		start.x = 0;
		start.y = y;
		end.x = img->map->x;
		end.y = y;
		ft_trace_line(start, end, img, LIGHT_BLUE);
	}
	x = -1;
	while (++x <= img->map->x)
	{
		start.x = x;
		start.y = 0;
		end.x = x;
		end.y = img->map->y;
		ft_trace_line(start, end, img, LIGHT_BLUE);
	}
}
