/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_negative_positive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:33:58 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 15:34:02 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

int			ft_color_positive(t_bres *bres)
{
	float	height;
	int		color;

	height = bres->z;
	if (height > 160)
		color = WHITE;
	else if (height > 100)
		color = BROWN;
	else if (height > 15)
		color = SAND;
	else if (height > 0)
		color = GREEN;
	else if (height > -7)
		color = LIGHT_BLUE;
	else if (height > -100)
		color = BLUE;
	else if (height <= -100)
		color = DEEP_BLUE;
	return (color);
}

int			ft_color_negative(t_bres *bres)
{
	float	height;
	int		color;

	height = bres->z;
	if (height > 160)
		color = DEEP_BLUE;
	else if (height > 100)
		color = BLUE;
	else if (height > 15)
		color = LIGHT_BLUE;
	else if (height > 0)
		color = GREEN;
	else if (height > -7)
		color = SAND;
	else if (height > -100)
		color = BROWN;
	else if (height <= -100)
		color = WHITE;
	return (color);
}
