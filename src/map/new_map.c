/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:46:23 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/10 14:12:28 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short			count_lines_and_col(t_data *data, char *str, short id)
{
	t_parse		p;

	p.i = -1;
	while (++p.i < (int)ft_strlen(str))
	{
		p.col = data->maps[id].width;
		data->maps[id].width = 0;
		p.tmp = 0;
		while (str[p.i] && str[p.i] != '\n')
		{
			if (p.tmp == 1 && str[p.i] != ',')
				return (0);
			if (p.tmp == 1 && str[p.i] == ',')
				p.tmp = 0;
			if (p.tmp == 0 && str[p.i] != ',')
				data->maps[id].width++;
			if (p.tmp == 0 && str[p.i] != ',')
				p.tmp = 1;
			p.i++;
		}
		if (data->maps[id].width != p.col && p.col != 0)
			return (0);
		data->maps[id].height++;
	}
	return (1);
}

char			*join_strings(char *s1, char *s2)
{
	char		*str;
	const int	l1 = (s1) ? ft_strlen(s1) : 0;
	const int	l2 = (s2) ? ft_strlen(s2) : 0;

	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}

char			*read_map(int fd)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	char		*tmp;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = join_strings(tmp, buf);
		free(tmp);
	}
	if (ret == -1 || !str)
		return (NULL);
	return (str);
}

void			allocate_map(t_data *data, short id)
{
	int			i;

	i = 0;
	if (!(data->maps[id].map =
				(int**)malloc(sizeof(int*) * data->maps[id].height)))
		clean_exit(data, "Map malloc error");
	nullify_tab((void**)data->maps[id].map, data->maps[id].height);
	while (i < data->maps[id].height)
	{
		if (!(data->maps[id].map[i] =
					(int*)malloc(sizeof(int) * data->maps[id].width)))
			clean_exit(data, "Map malloc error");
		i++;
	}
}

short			map_too_big(char *name)
{
	int			fd;
	int			i;
	int			len;
	int			objects;
	char		*line;

	fd = open(name, O_NOCTTY | O_RDONLY | O_NOFOLLOW | O_NONBLOCK);
	len = 0;
	objects = 0;
	while (get_next_line(fd, &line) > 0)
	{
		len += ft_strlen(line);
		i = -1;
		while (line[++i] != '\0')
			if (line[i] == 'E' || line[i] == 'L' || line[i] == 'D'
					|| line[i] == 'K' || line[i] == 'S' || line[i] == 'B'
					|| line[i] == 'C')
				objects++;
		free(line);
		if (len > 5000 || objects > 100)
			return (1);
	}
	close(fd);
	free(line);
	return (0);
}

void			new_map(t_data *data, char *title, short id)
{
	int			fd;
	char		*str;

	if (map_too_big(title))
		clean_exit(data, "Map is too big or has too many enemies");
	fd = open(title, O_NOCTTY | O_RDONLY | O_NOFOLLOW | O_NONBLOCK);
	if (!(str = read_map(fd)))
		clean_exit(data, "Read error");
	if (!count_lines_and_col(data, str, id))
		clean_exit(data, "Map is not rectangular");
	str = ft_replace(str, '\n', ',');
	close(fd);
	allocate_map(data, id);
	fill_raw_map(data, str, id);
	parse_map(data, str, id);
	free(str);
}
