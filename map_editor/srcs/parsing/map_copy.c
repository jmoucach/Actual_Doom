/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:55:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/11 10:57:47 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

int				atoi_or_number(char *str)
{
	if (str[0] >= '0' && str[0] <= '6')
		return (ft_atoi(str));
	else if (str[0] == 'P')
		return (7);
	else if (str[0] == 'E')
		return (8);
	else if (str[0] == 'S')
		return (9);
	else if (str[0] == 'B')
		return (10);
	else if (str[0] == 'C')
		return (11);
	else if (str[0] == 'H')
		return (12);
	else if (str[0] == 'O')
		return (13);
	else if (str[0] == '7')
		return (14);
	return (0);
}

int				*ft_str_to_int(char *charline, int len)
{
	int			i;
	int			j;
	int			*intline;
	static int	y = 0;

	i = 0;
	j = 0;
	if (!(intline = malloc(sizeof(t_point) * (len))))
		return (NULL);
	while (i < len)
	{
		while (charline[j] != '\0')
		{
			while (charline[j] == ',')
				j++;
			intline[i] = atoi_or_number(charline + j);
//			ft_putnbr(intline[i]);//DEBUG
			i++;
			while (ft_conform_char(charline[j]) == 1)
				j++;
		}
		y++;
	}
	return (intline);
}

int				*ft_fill_map(char *charline, int *len)
{
	int			i;
	int			*line;

	i = 0;
	*len = 0;
	while (charline[i] != '\0')
	{
		if (ft_conform_char(charline[i]) == 1)
		{
			(*len)++;
			i++;
		}
//		while (ft_conform_char(charline[i]) == 1)
		//while (ft_isdigit(charline[i]) == 1)
//			i++;
		while (charline[i] == ',')
			i++;
	}
	line = ft_str_to_int(charline, *len);
	return (line);
}

t_map			*ft_map_copy(t_line *list)
{
	t_line		*tmp;
	t_map		*map;
	int			i;
	char		*conform_line;

	i = -1;
	if (!list || !(map = malloc(sizeof(t_map))))
		return (NULL);
	map->x = 0;
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	//ft_putnbr(tmp->y);//DEBUG
	map->y = tmp->y + 1;
	if (!(map->map = malloc(sizeof(int *) * (map->y + 1))))
		return (0);
	tmp = list;
	while (++i < map->y)
	{
		conform_line = ft_conform_line(tmp->str);
		map->map[i] = ft_fill_map(conform_line, &tmp->x);
		map->x = tmp->x;
		tmp = tmp->next;
	}
	return (map);
}
