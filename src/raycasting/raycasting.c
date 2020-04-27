/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:22:58 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 18:03:45 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void	cast_one_pixel(t_data *data, t_raycast *r, t_point pt)
{
	r->tex.y = (pt.y * 2 - (SCREEN_HEIGHT + data->yaw) + r->lineheight)
									* (r->texh / 2) / (r->lineheight + 1);
	r->color = get_pixel(data->surface[r->texnum],
						r->tex.x, r->tex.y);
	data->pixels[pt.x + pt.y * SCREEN_WIDTH] = shaded_color(data,
											r->color, r->walldist, NULL);
}

void	*cast_one_column(void *d)
{
	t_data	*data;
	t_raycast	r;
	t_point		pt;

	data = (t_data*)d;
	pt.x = 0;
	while (pt.x < NB_THREAD && pthread_self() != data->thread[pt.x])
		pt.x++;
	while (pt.x < SCREEN_WIDTH)
	{
		set_raycast_values(&r, data->p, pt.x);
		set_dist_and_step(&r);
		hit_wall(&r, data);
		get_texturing_values(&r, data);
		give_draw_values(&r, data);
		pt.y = r.drawstart - 1;
		while (++pt.y <= r.drawend && is_in_frame(pt))
			cast_one_pixel(data, &r, pt);
		data->zbuffer[pt.x] = r.walldist;
		floorcaster(data, &r, pt.x);
		pt.x += NB_THREAD;
	}
	pthread_exit(0);
}

void	raycasting(t_data *data)
{
	short		i;

	i = -1;
	while (++i < NB_THREAD)
	{
		if (pthread_create(&data->thread[i], NULL, cast_one_column, data))
			clean_exit(data, "pthread_create error");
	}
	i = -1;
	while (++i < NB_THREAD)
		if (pthread_join(data->thread[i], NULL))
			clean_exit(data, "pthread_join error");
}
