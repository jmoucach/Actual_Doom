/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:22:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/10 19:19:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/map_editor.h"
/*
Uint32			get_pixel(SDL_Surface *s, int x, int y)
{
	int			bpp;
	Uint8		*p;

	bpp = s->format->BytesPerPixel;
	p = s->pixels + y * s->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16*)p);
	else if (bpp == 3)
		return ((p[0]) | (p[1] << 8) | (p[2] << 16));
	else
		return (*(Uint32*)p);
}*/

SDL_Texture		*loadimage(char *path, t_fdf *img)
{
	SDL_Surface *loadedsurface;
	SDL_Texture	*texture;

	loadedsurface = SDL_LoadBMP(path);
	if (!loadedsurface)
	{
		ft_putstr_fd("Couldn't load image:", 2);
		ft_putendl_fd(path, 2);
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		return (NULL);
	}
	if (!(texture = SDL_CreateTextureFromSurface(img->renderer, loadedsurface)))
		ft_putendl_fd(SDL_GetError(), 2);
	SDL_FreeSurface(loadedsurface);
	return (texture);
}

char			**path_to_textures(void)
{
	char		**path_tab;
	
	if (!(path_tab = malloc(sizeof(char *) * 19)))
		return (NULL);
	path_tab[0] = NULL;
	path_tab[1] = ft_strdup("../pics/bluestone.bmp");
	path_tab[2] = ft_strdup("../pics/greystone.bmp");
	path_tab[3] = ft_strdup("../pics/mossy.bmp");
	path_tab[4] = ft_strdup("../pics/tile2.bmp");
	path_tab[5] = ft_strdup("../pics/wood.bmp");
	path_tab[6] = ft_strdup("../pics/redbrick.bmp");
	path_tab[7] = ft_strdup("../sprites/doom_guy_face.bmp");
	path_tab[8] = ft_strdup("../sprites/enemy_face.bmp");
	path_tab[9] = ft_strdup("../sprites/soul_button.bmp");
	path_tab[10] = ft_strdup("../sprites/boss_button.bmp");
	path_tab[11] = ft_strdup("../pics/keydoor.bmp");
	path_tab[12]= ft_strdup("../pics/pillar.bmp");
	path_tab[13] = ft_strdup("../sprites/shells_button.bmp");
	path_tab[14] = ft_strdup("../sprites/bullets_button.bmp");
	path_tab[15] = ft_strdup("../sprites/cell_button.bmp");
	path_tab[16] = ft_strdup("../sprites/health_button.bmp");
	path_tab[17] = ft_strdup("../sprites/key_button.bmp");
	path_tab[18] = ft_strdup("../sprites/pickups/armor_pu.bmp");
	path_tab[19] = NULL;
	return (path_tab);
}

short			loadmedia(t_fdf *img)
{
	int			i;
	char		**path_tab;

	i = 0;
	path_tab = path_to_textures();
	img->texture[0] = NULL;
	while (++i <= 18)
	{
		img->texture[i] = loadimage(path_tab[i], img);
		if (!img->texture[i])
		return (0);
	}
	return (1);
}
