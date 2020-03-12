/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:51 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

void			print_map(t_data data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data.msize.y)
	{
		j = 0;
		while (j < data.msize.x)
		{
			ft_putnbr(data.map[i][j]);
			ft_putstr(", ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static void		add_one_item(t_data *data, int i, int type, int *o_num)
{
	addback_object(&(data->obj), new_object(*o_num, type,
				(t_d_point){(i / 2) / data->msize.x + 0.5,
				(i / 2) % data->msize.x + 0.5}));
	data->map[(i / 2) / data->msize.x]
		[(i / 2) % data->msize.x] = 0;
	(*o_num)++;
}

static void		item_selection(t_data *data, int i, char c, int *o_num)
{
	if (c == 'O')
		add_one_item(data, i, 1, o_num);
	else if (c == 'B')
		add_one_item(data, i, 2, o_num);
	else if (c == 'S')
		add_one_item(data, i, 3, o_num);
	else if (c == 'C')
		add_one_item(data, i, 4, o_num);
	else if (c == 'H')
		add_one_item(data, i, 5, o_num);
	else if (c == 'A')
		add_one_item(data, i, 6, o_num);
	else if (c == 'K')
		add_one_item(data, i, 7, o_num);
	else if (c == 'E')
		add_one_item(data, i, 0, o_num);
}

void			fill_map(t_data *data, char *str)
{
	int			i;
	int			o_num;

	parse_map(data, str);
	i = 0;
	o_num = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			data->p.pos.x = (i / 2) / data->msize.x + 0.5;
			data->p.pos.y = (i / 2) % data->msize.x + 0.5;
			data->map[(i / 2) / data->msize.x]
				[(i / 2) % data->msize.x] = 0;
		}
		else if (str[i] >= '0' && str[i] <= '7')
		{
			data->map[(i / 2) / data->msize.x]
				[(i / 2) % data->msize.x] = str[i] - '0';
		}
		else
			item_selection(data, i, str[i], &o_num);
		i++;
	}
}
