/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:39:53 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/25 16:52:32 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short	get_dying_sprite(t_data *data, t_object *obj)
{
	short	removed;

	removed = 0;
	obj->lastUpdate += data->ftime;
	if (obj->current_sprite < obj->first_sprite_death
		|| obj->current_sprite > obj->first_sprite_death
		+ obj->num_of_sprites_death)
	{
		obj->lastUpdate = 0;
		obj->current_sprite = obj->first_sprite_death;
	}
	else if (obj->lastFrame == obj->num_of_sprites_death - 1)
		removed = 1;
	else if (obj->lastUpdate >= 0.5 / obj->num_of_sprites_death)
	{
		obj->lastFrame++;
		obj->lastFrame %= obj->num_of_sprites_death;
		obj->lastUpdate = 0;
		obj->current_sprite = obj->first_sprite_death + obj->lastFrame;
	}
	return (removed);
}

void	enemy_death(t_data *data, t_object *obj)
{
	if (get_dying_sprite(data, obj) == 1)
		remove_object(&(data->obj), obj->id_key);
}
