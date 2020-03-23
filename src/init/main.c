/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2020/03/11 17:02:10 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

short	name_parser(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (!ft_strequ((file_name + i - 5), ".doom"))
	{
		ft_putstr_fd("Invalid map_name", 2);
		return (0);
	}
	return (1);
}

void	free_maps(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 4)
	{
		i = data->maps[j].height - 1;
		while (i >= 0)
		{
			free(data->maps[j].map[i]);
			i--;
		}
		free(data->maps[j].map);
	}
}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac <= 2)
	{
		set_values(&data, ac);
		init(&data);
		loadmedia(&data);
		prepare_hud(&data);
		load_story_maps(&data);
		if (ac == 2)
		{
			if (name_parser(av[1]))
				new_map(&data, av[1]);
			else
				clean_exit(&data, "");
		}
		game_loop(&data);
		free_maps(&data);
		delete_cur_map(&data);
		clean_exit(&data, NULL);
	}
	return (0);
}
