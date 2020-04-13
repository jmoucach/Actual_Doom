/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:04:47 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/04 19:46:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"

void		ft_free_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->y)
		free(map->map[i]);
	free(map);
}

void		ft_free_fdf(t_fdf *fdf)
{
//	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
//	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	ft_free_map(fdf->map);
//	free(fdf->mlx_ptr);
	free(fdf);
}

void		ft_free_line(t_line *list)
{
	t_line	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->str);
		free(tmp);
	}
	free(list);
}
/*
static void	free_surf_and_sprites(t_data *data)
{
	int	i;

	if (data->surface && (i = -1))
	{
		while (++i < 20)
			if (data->surface[i])
				SDL_FreeSurface(data->surface[i]);
		free(data->surface);
	}
	if (data->sprites)
	{
		i = -1;
		while (++i < 33)
			if (data->sprites[i])
				SDL_DestroyTexture(data->sprites[i]);
		free(data->sprites);
	}
	if (data->obj_sprite)
	{
		i = -1;
		while (++i < 44)
			if (data->obj_sprite[i].surf)
				SDL_FreeSurface(data->obj_sprite[i].surf);
		free(data->obj_sprite);
	}
}*/

static void	ft_free_textures(t_fdf *img)
{
	int		i;

	i = 0;
	while (++i < 18)
	{
		if (img->texture[i] != NULL)
			SDL_DestroyTexture(img->texture[i]);
	}
	if (img->grid != NULL)
		SDL_DestroyTexture(img->grid);
	/*if (data->hud.hud_texture)
		SDL_DestroyTexture(data->hud.hud_texture);
	if (data->hud.face_texture)
		SDL_DestroyTexture(data->hud.face_texture);
	if (data->hud.hp_text)
		SDL_DestroyTexture(data->hud.hp_text);
	if (data->hud.armor_text)
		SDL_DestroyTexture(data->hud.armor_text);
	if (data->hud.bullets_text)
		SDL_DestroyTexture(data->hud.bullets_text);
	if (data->hud.shells_text)
		SDL_DestroyTexture(data->hud.shells_text);
	if (data->hud.cells_text)
		SDL_DestroyTexture(data->hud.cells_text);
	if (data->hud.ammo_text)
		SDL_DestroyTexture(data->hud.ammo_text);
	if (data->hud.hud_texture)
		SDL_DestroyTexture(data->hud.infinite_text);*/
}

void		ft_clean_exit(t_fdf *img, char *err)
{
	if (err)
		ft_putendl_fd(err, 2);
	ft_free_textures(img);
	/*
	free_surf_and_sprites(data);
	free_hud(data);
	free_objects(data);
	if (data->zBuffer)
		free(data->zBuffer);
	if (data->pixels)
		free(data->pixels);
	if (data->texture)
		SDL_DestroyTexture(data->texture);*/
	if (img->renderer)
		SDL_DestroyRenderer(img->renderer);
	if (img->window)
		SDL_DestroyWindow(img->window);
	if (TTF_WasInit())
		TTF_Quit();
	if (SDL_WasInit(SDL_INIT_VIDEO) & SDL_INIT_VIDEO)
		SDL_Quit();
	if (err)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}