/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_vision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JP <JP@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:38:27 by JP                #+#    #+#             */
/*   Updated: 2020/03/25 16:43:25 by JP               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short   can_see_player(t_data *data, t_object *obj)
{
    t_ray ray;
    t_point m_pos;
    t_d_point deltadist;
    t_d_point sidedist;
    t_point step;

    ray.pos.x = obj->pos.x;
    ray.pos.y = obj->pos.y;
    ray.dir.x = data->p.pos.x - obj->pos.x;
    ray.dir.y = data->p.pos.y - obj->pos.y;
    m_pos.x = (int)obj->pos.x;
    m_pos.y = (int)obj->pos.y;
    deltadist.x = sqrt(1 + (ray.dir.y * ray.dir.y) / (ray.dir.x * ray.dir.x));
    deltadist.y = sqrt(1 + (ray.dir.x * ray.dir.x) / (ray.dir.y * ray.dir.y));


if (ray.dir.x < 0)
	{
		step.x = -1;
		sidedist.x = (ray.pos.x - m_pos.x) * deltadist.x;
	}
	else
	{
		step.x = 1;
		sidedist.x = (m_pos.x + 1.0 - ray.pos.x) * deltadist.x;
	}
	if (ray.dir.y < 0)
	{
		step.y = -1;
		sidedist.y = (ray.pos.y - m_pos.y) * deltadist.y;
	}
	else
	{
		step.y = 1;
		sidedist.y = (m_pos.y + 1.0 - ray.pos.y) * deltadist.y;
	}

	while (1)
	{
		if (sidedist.x < sidedist.y)
		{
			sidedist.x += deltadist.x;
			m_pos.x += step.x;
		}
		else
		{
			sidedist.y += deltadist.y;
			m_pos.y += step.y;
		}
		if (data->cur_map.map[m_pos.x][m_pos.y] > 0)
			return (0);
		if (m_pos.x == (int)data->p.pos.x && m_pos.y == (int)data->p.pos.y)
			return (1);
	}
	return (1);
}