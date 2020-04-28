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

void	*cast_window_column(void *d)
{
	t_raycast	r;
	t_point		pt;

	pt.x = 0;
	while (pt.x < NB_THREAD && pthread_self() != ((t_data*)d)->thread[pt.x])
		pt.x++;
	while (pt.x < SCREEN_WIDTH)
	{
		set_raycast_values(&r, ((t_data*)d)->p, pt.x);
		set_dist_and_step(&r);
		while (hit_wall(&r, ((t_data*)d)) == 2)
		{
			column_calc(((t_data*)d), &r, pt);
			if (pt.x == SCREEN_WIDTH / 2 && r.texnum == 7
					&& (((t_data*)d)->window_dist > r.walldist
						|| !((t_data*)d)->window_dist))
			{
				((t_data*)d)->is_window.x = r.m_pos.x;
				((t_data*)d)->is_window.y = r.m_pos.y;
				((t_data*)d)->window_dist = r.walldist;
			}
		}
		pt.x += NB_THREAD;
	}
	pthread_exit(0);
}

void	windowcasting(t_data *data)
{
	short		i;

	data->hit_window = 0;
	data->window_dist = 0;
	i = -1;
	while (++i < NB_THREAD)
	{
		if (pthread_create(&data->thread[i], NULL, cast_window_column, data))
			clean_exit(data, "pthread_create error");
	}
	i = -1;
	while (++i < NB_THREAD)
		if (pthread_join(data->thread[i], NULL))
			clean_exit(data, "pthread_join error");
}
