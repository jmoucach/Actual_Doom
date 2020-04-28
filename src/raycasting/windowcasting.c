/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowcasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:22:58 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 18:03:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	windowcasting(t_data *data)
{
	t_raycast	r;
	t_point		pt;

	data->hit_window = 0;
	data->window_dist = 0;
	pt.x = 0;
	while (pt.x < NB_THREAD && data->thread[pt.x] != pthread_self())
		pt.x++;
	while (pt.x < SCREEN_WIDTH)
	{
		set_raycast_values(&r, data->p, pt.x);
		set_dist_and_step(&r);
		while (hit_wall(&r, data) == 2)
		{
			column_calc(data, &r, pt);
			if (pt.x == SCREEN_WIDTH / 2 && r.texnum == 7
					&& (data->window_dist > r.walldist
						|| !data->window_dist))
			{
				data->is_window.x = r.m_pos.x;
				data->is_window.y = r.m_pos.y;
				data->window_dist = r.walldist;
			}
		}
		pt.x += NB_THREAD;
	}
}
