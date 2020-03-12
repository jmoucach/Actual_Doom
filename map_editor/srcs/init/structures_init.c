/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:32:31 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 17:54:41 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

int			ft_sdl_init(t_fdf *ptr, char *name)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error((char *)SDL_GetError(), 2);
	if (TTF_Init() < 0)
		ft_error((char *)TTF_GetError(), 2);
	if (!(ptr->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, 
					SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0)))
		ft_error((char *)SDL_GetError(), 2);
	if (!(ptr->renderer = SDL_CreateRenderer(ptr->window, -1, 0)))
		ft_error((char *)SDL_GetError(), 2);
//		ptr->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 500, 300);
	//}
	ft_putendl("ok sdl_init");//DEBUG
	return (1);
}

t_fdf			*ft_ptr_init(char *name)
{
	t_fdf		*ptr;

	if (!(ptr = malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(ft_sdl_init(ptr, NAME)))
		return (NULL);
	if (!(ptr->txt = ft_txt_init(ptr)))
		return (NULL);
	if (!(ptr->texture = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 14)))
		exit(EXIT_FAILURE);
	nullify_textures(ptr);
	loadmedia(ptr);
	ptr->map_name = name;
	ptr->bpp = 32;
	ptr->s_l = WIDTH * 4;
	ptr->height = HEIGHT;
	ptr->endian = 0;
	ptr->color = ft_hexa_to_SDL(LIGHT_BLUE);//MAKE THE COLOR CHANGEABLE
	ptr->pixels = (Uint8*)malloc(sizeof(Uint8) * (WIDTH * HEIGHT));
	ft_bzero(ptr->pixels, (WIDTH * HEIGHT * sizeof(Uint8)));
	ft_putendl("ok ptr_init");//DEBUG
	return (ptr);
}

t_point		*ft_init_coord(int x, int y)
{
	t_point	*p;

	if (!(p = malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	ft_putendl("ok init_coord");//DEBUG
	return (p);
}

t_map			*ft_map_init(t_line *list)
{
	t_map		*map;

	if (!(map = ft_map_copy(list)))
		return (NULL);
	map->base_gap = ft_gap(map);
	map->base_h = ft_height(map);
	map->zmax = 1;//when we can give altitude to elements, we'll parse the list to save the highest value.
	ft_origin(map);
	map->endx = map->ox + ((map->x - 1) * map->base_gap);
	map->endy = map->oy + ((map->y - 1) * map->base_gap);
	ft_putendl("ok map_init");//DEBUG
	return (map);
}
