/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:55:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/07/03 15:11:07 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_horizontal(t_bres *bres, t_fdf *img)
{
	bres->error = bres->dx / 2;
	bres->i = 0;
	while (++bres->i <= bres->dx)
	{
		bres->x = bres->x + bres->xinc;
		bres->error = bres->error + bres->dy;
		if (bres->error >= bres->dx)
		{
			bres->error = bres->error - bres->dx;
			bres->y = bres->y + bres->yinc;
			bres->z = bres->z + bres->yinc * bres->dz / bres->dy;
		}
		ft_light_up_pixel(bres, img);
	}
}

void		ft_vertical(t_bres *bres, t_fdf *img)
{
	bres->error = bres->dy / 2;
	bres->i = 0;
	while (++bres->i <= bres->dy)
	{
		bres->y = bres->y + bres->yinc;
		bres->z = bres->z + bres->yinc * bres->dz / bres->dy;
		bres->error = bres->error + bres->dx;
		if (bres->error >= bres->dy)
		{
			bres->error = bres->error - bres->dy;
			bres->x = bres->x + bres->xinc;
		}
		ft_light_up_pixel(bres, img);
	}
}

void		ft_bresenham(t_point a, t_point b, t_fdf *img)
{
	t_bres		bres;

	bres.x = a.x * img->map->base_gap;
	bres.dx = (b.x - a.x) * img->map->base_gap;
	bres.z = a.z;
	bres.dz = b.z - a.z;
	if (img->map->proj == 'I')
	{
		bres.y = a.y * img->map->base_gap - a.z * img->map->base_h;
		bres.dy = (b.y - a.y) * img->map->base_gap -
			(b.z - a.z) * img->map->base_h;
	}
	if (img->map->proj == 'C')
	{
		bres.y = a.y * img->map->base_gap;
		bres.dy = (b.y - a.y) * img->map->base_gap;
	}
	bres.xinc = (bres.dx > 0) ? 1 : -1;
	bres.yinc = (bres.dy > 0) ? 1 : -1;
	bres.dx = ft_abs(bres.dx);
	bres.dy = ft_abs(bres.dy);
	if (bres.dx > bres.dy)
		ft_horizontal(&bres, img);
	else
		ft_vertical(&bres, img);
}
