/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:40:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/06 16:00:57 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 
#include "../hdr/map_editor.h"

int			ft_color(t_bres *bres, int sign)
{
	if (sign == 'P')
		return (ft_color_positive(bres));
	if (sign == 'N')
		return (ft_color_negative(bres));
	return (0);
}

void		ft_light_up_pixel(t_bres *bres, t_fdf *img)
{
	int		p;
	int		origin;
	int		x;
	int		y;

	x = bres->x;
	y = bres->y;
	bres->color = ft_color(bres, img->color);
	if (img->map->ox + x >= WIDTH || img->map->ox + x <= 0 ||
			img->map->oy + y >= HEIGHT || img->map->oy + y <= 0)
		return ;
	origin = img->map->ox * 4 + img->map->oy * img->s_l;
	p = origin + ((x * 4) + (y * img->s_l));
	if (p >= 0 && (p + 3) < (WIDTH * img->s_l))
	{
		img->str[p] = (bres->color & 0xff);
		img->str[p + 1] = (bres->color & 0xff00) >> 8;
		img->str[p + 2] = (bres->color & 0xff0000) >> 16;
		img->str[p + 3] = 5;
	}
}

void		ft_print_lines(t_fdf *img, t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (x < map->x - 1)
				ft_bresenham(map->map[y][x], map->map[y][x + 1], img);
			if (y < map->y - 1)
				ft_bresenham(map->map[y][x], map->map[y + 1][x], img);
		}
	}
}

void		ft_fill_image(t_fdf *img, t_map *map)
{
	map->base_gap = ft_gap(map);
	map->base_h = ft_height(map);
	ft_origin(map);
	ft_print_lines(img, map);
}
