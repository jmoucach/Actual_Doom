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

void	free_map(t_data *data)
{
	int	i;

	i = data->msize.y - 1;
	while (i >= 0)
	{
		free(data->map[i]);
		i--;
	}
	free(data->map);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		set_values(&data);
		init(&data);
		loadmedia(&data);
		prepare_hud(&data);
		if (name_parser(av[1]))
		{
			new_map(&data, av[1]);
			game_loop(&data);
			free_map(&data);
		}
		else
			clean_exit(&data, "");
		clean_exit(&data, NULL);
	}
	return (0);
}
