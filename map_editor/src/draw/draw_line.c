/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/26 12:49:25 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void				setup_param(t_pt pt_one, t_pt pt_two,
	t_line_param *line_param)
{
	line_param->diff.x = ft_abs(pt_two.x - pt_one.x);
	line_param->diff.y = ft_abs(pt_two.y - pt_one.y);
	line_param->off = line_param->diff.x - line_param->diff.y;
	line_param->inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	line_param->inc.y = (pt_one.y < pt_two.y ? 1 : -1);
}

void				draw_line(t_pt pt_one, t_pt pt_two,
	Uint32 *pixels, int colour)
{
	t_pt			pt;
	t_line_param	line_param;
	Uint32			*pix;

	pix = pixels;
	setup_param(pt_one, pt_two, &line_param);
	pt = pt_one;
	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		pix[pt.x + pt.y/* * WIDTH*/] = colour;
		if ((line_param.error = line_param.off * 2) > -line_param.diff.y)
		{
			line_param.off -= line_param.diff.y;
			pt.x += line_param.inc.x;
		}
		if (line_param.error <= line_param.diff.x)
		{
			line_param.off += line_param.diff.x;
			pt.y += line_param.inc.y;
		}
	}
	pix[pt.x + pt.y/* * WIDTH*/] = colour;
}
