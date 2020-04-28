/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectcasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:04:52 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 18:00:29 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			get_dist_to_player(t_data *data)
{
	t_object	*iterator;

	iterator = data->obj;
	while (iterator)
	{
		iterator->dist_to_player = sqrt((iterator->pos.x - data->p.pos.x)
			* (iterator->pos.x - data->p.pos.x)
			+ (iterator->pos.y - data->p.pos.y)
			* (iterator->pos.y - data->p.pos.y));
		iterator = iterator->next;
	}
}

int				get_movescreen_value(t_data *data, t_objcast o, int pos)
{
	int hyp_height;
	int hyp_drawend;

	if (pos == GROUND)
	{
		hyp_height = abs((int)(SCREEN_HEIGHT / o.pos.y));
		hyp_drawend = hyp_height / 2 + (SCREEN_HEIGHT + data->yaw) / 2;
		return (hyp_drawend - o.drawend.y);
	}
	return (0);
}

static void		draw_object(t_data *data, t_objcast o, SDL_Surface *surf,
									t_object *obj)
{
	int			x;
	int			y;

	x = o.drawstart.x - 1;
	while (++x < o.drawend.x)
	{
		o.tex.x = (x - (-o.width / 2 + o.screen_x)) * surf->w / o.width;
		y = o.drawstart.y - 1;
		if (o.pos.y > 0 && x > 0 && x < SCREEN_WIDTH
				&& o.pos.y < data->zbuffer[x])
		{
			obj->visible = 1;
			while (++y < o.drawend.y)
			{
				o.tex.y = ((y - o.movescreen) * 2 - (SCREEN_HEIGHT + data->yaw)
						+ o.height) * (surf->h / 2) / (o.height + 1);
				o.color = get_pixel(surf, o.tex.x, o.tex.y);
				if (o.color != 0 && is_in_frame((t_point){x, y}))
				{
					data->e_zbuffer[x + y * SCREEN_WIDTH] = obj->dist_to_player;
					data->pixels[x + y * SCREEN_WIDTH] = shaded_color(data,
							o.color, obj->dist_to_player, obj);
				}
			}
		}
	}
}

void			objectcaster(t_data *data, t_object *obj)
{
	t_objcast	o;
	t_sprite	sprite;

	obj->visible = 0;
	sprite = data->obj_sprite[obj->current_sprite];
	set_objcast_values(data, &o, obj, sprite);
	draw_object(data, o, sprite.surf, obj);
}
