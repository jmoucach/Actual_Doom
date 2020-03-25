/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_new_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:08:30 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 17:05:13 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void		write_objects(int i, int fd)
{

	if (i == 7)
		ft_putchar_fd('P', fd);
	else if (i == 8)
		ft_putchar_fd('E', fd);
	else if (i == 9)
		ft_putchar_fd('S', fd);
	else if (i == 10)
		ft_putchar_fd('B', fd);
	else if (i == 11)
		ft_putchar_fd('C', fd);
	else if (i == 12)			//this is wrong
		ft_putchar_fd('H', fd);
	else if (i == 12)
		ft_putchar_fd('O', fd);
	else if (i == 14)
		ft_putchar_fd('L', fd);
	else if (i == 15)
		ft_putchar_fd('K', fd);
	else if (i == 15)
		ft_putchar_fd('K', fd);
	else if (i == 16)
		ft_putchar_fd('7', fd);
}

void		write_tab(int **tab, int width, int height, int fd)
{
	int		x;
	int		y;

	//ft_putendl("Ok entree write_tab");//DEBUG
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width -1)
		{
			if (tab[y][x] <= 6)
				ft_putnbr_fd(tab[y][x], fd);
			else
				write_objects(tab[y][x], fd);
			ft_putchar_fd(',', fd);
		}
		ft_putnbr_fd(tab[y][x], fd);
		if (y != height -1)
			ft_putchar_fd('\n', fd);
	}
}

void		ft_save_map(t_fdf *img)
{
	int		fd;
	int		**int_tab;
	int		width;
	int		height;

	int_tab = img->map->map;
	width = img->map->x;
	height = img->map->y;
	//ft_putendl("Ok entree ft_save_map");
	if ((fd = open(img->map_name, O_RDWR | O_TRUNC, 0666)) <= 0)
	{
		ft_putendl(ft_itoa(fd));
		ft_error("Unable to write in the map file", 2);
	}
	write_tab(int_tab, width, height, fd);
	//free_tab(img->map->map);
	ft_putstr("Map updated succesfully\n");
	exit (0);
}
