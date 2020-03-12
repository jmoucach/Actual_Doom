/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:20:07 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 16:04:46 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_clear_and_replace(t_fdf *ptr)
{
	ft_bzero(ptr->str, ptr->bpp * HEIGHT * WIDTH / 8);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ft_print_lines(ptr, ptr->map);
}

int			ft_key_press(int key, t_fdf *ptr)
{
	if (key == 53)
	{
		ft_free_fdf(ptr);
		exit(0);
	}
	if (key == 12 || key == 6)
		ft_modify_height(key, ptr);
	if (key == 78 || key == 69)
		ft_zoom(key, ptr);
	if (key > 122 && key < 127)
		ft_move(key, ptr);
	if (key == 8 || key == 34)
		ft_iso_or_cart(key, ptr);
	if (key == 35 || key == 45)
		ft_positive_or_negative(key, ptr);
	ft_clear_and_replace(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ft_print_menu(ptr->mlx_ptr, ptr->win_ptr);
	return (1);
}

void		ft_get_controls(t_fdf *ptr)
{
	mlx_hook(ptr->win_ptr, 2, 0, ft_key_press, ptr);
}
