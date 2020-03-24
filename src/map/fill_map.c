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

void			print_map(t_map map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			ft_putnbr(map.map[i][j]);
			ft_putstr(",\t");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			delete_cur_map(t_data *data)
{
	int			i;

	i = -1;
	if (data->cur_map.map)
	{
		while (++i < data->cur_map.height)
			if (data->cur_map.map[i])
				free(data->cur_map.map[i]);
		free(data->cur_map.map);
		data->cur_map.map = NULL;
	}
}

int				alloc_cur_map(t_data *data, t_map map)
{
	int			i;

	if (!(data->cur_map.map = (int**)malloc(sizeof(int*) * map.height)))
		return (0);
	i = -1;
	while (++i < map.height)
		if (!(data->cur_map.map[i] = (int*)malloc(sizeof(int) * map.width)))
		{
			while (--i >= 0)
				free(data->cur_map.map[i]);
			free(data->cur_map.map);
			return (0);
		}
	return (1);
}

int				copy_cur_map(t_data *data)
{
	int			i;
	int			j;
	int			m;

	m = data->menu_sel;
	if (!alloc_cur_map(data, data->maps[m]))
		return (0);
	data->cur_map.width = data->maps[m].width;
	data->cur_map.height = data->maps[m].height;
	i = -1;
	while (++i < data->maps[m].height)
	{
		j = -1;
		while (++j < data->maps[m].width)
			data->cur_map.map[i][j] = data->maps[m].map[i][j];
	}
	return (1);
}

static void		add_one_item(t_data *data, t_point coords, int type, int *o_num)
{
	addback_object(&(data->obj), new_object(*o_num, type,
				(t_d_point){coords.x + 0.5,
				coords.y + 0.5}));
	data->cur_map.map[coords.x][coords.y] = 0;
	(*o_num)++;
}

static void		item_selection(t_data *data, t_point coords, char c, int *o_num)
{
	if (c == 'O')
		add_one_item(data, coords, 2, o_num);
	else if (c == 'B')
		add_one_item(data, coords, 3, o_num);
	else if (c == 'S')
		add_one_item(data, coords, 4, o_num);
	else if (c == 'C')
		add_one_item(data, coords, 5, o_num);
	else if (c == 'H')
		add_one_item(data, coords, 6, o_num);
	else if (c == 'A')
		add_one_item(data, coords, 7, o_num);
	else if (c == 'K')
		add_one_item(data, coords, 8, o_num);
	else if (c == 'E')
		add_one_item(data, coords, 0, o_num);
	else if (c == 'L')
		add_one_item(data, coords, 1, o_num);
}

void			fill_input_map(t_data *data, char *str)
{
	int			i;
	int			j;

	i = -1;
	while (++i < data->maps[3].height)
	{
		j = -1;
		while (++j < data->maps[3].width)
			data->maps[3].map[i][j] = str[j * 2 + i * 2 * data->maps[3].width];
	}
}

void			fill_map(t_data *data, t_map map)
{
	int			i;
	int			j;
	int			o_num;

	i = -1;
	o_num = 0;
	// on lit map et on remplit data->cur_map
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if (map.map[i][j] == 'P')
			{
				data->p.pos.x = i + 0.5;
				data->p.pos.y = j + 0.5;
				data->cur_map.map[i][j] = 0;
			}
			else if (map.map[i][j] >= '0' && map.map[i][j] <= '7')
			{
				data->cur_map.map[i][j] = map.map[i][j] - '0';
			}
			else
				item_selection(data, (t_point){i, j}, map.map[i][j], &o_num);
		}
	}
}