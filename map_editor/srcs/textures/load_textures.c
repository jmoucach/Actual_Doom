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

#include "../../map_editor.h"
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

short			load_textures(t_fdf *img)
{
	img->texture[0] = NULL;
	img->texture[1] = loadimage("../pics/bluestone.bmp", img);
	if (!img->texture[1])
		return (0);
	img->texture[2] = loadimage("../pics/greystone.bmp", img);
	if (!img->texture[2])
		return (0);
	img->texture[3] = loadimage("../pics/mossy.bmp", img);
	if (!img->texture[3])
		return (0);
	img->texture[4] = loadimage("../pics/tile2.bmp", img);
	if (!img->texture[4])
		return (0);
	img->texture[5] = loadimage("../pics/wood.bmp", img);
	if (!img->texture[5])
		return (0);
	img->texture[6] = loadimage("../pics/redbrick.bmp", img);
	if (!img->texture[6])
		return (0);
	img->texture[7] = loadimage("../sprites/doom_guy_face.bmp", img);
	if (!img->texture[7])
		return (0);
	img->texture[8] = loadimage("../sprites/enemy_face.bmp", img);
	if (!img->texture[8])
		return (0);
	img->texture[9] = loadimage("../sprites/soul_button.bmp", img);
	if (!img->texture[9])
		return (0);
//	img->texture[10] = loadimage("../sprites/", img);//TO CHANGE WITH BOSS IMAGE
//	if (!img->texture[10])
//		return (0);
	img->texture[11] = loadimage("../pics/keydoor.bmp", img);
	if (!img->texture[11])
		return (0);
	img->texture[12] = loadimage("../pics/pillar.bmp", img);
	if (!img->texture[12])
		return (0);
	ft_putendl("Ok load_textures");
	return (1);
}

short			load_objects(t_fdf *img)
{
	img->texture[13] = loadimage("../sprites/shells_button.bmp", img);
	if (!img->texture[13])
		return (0);
	img->texture[14] = loadimage("../sprites/bullets_button.bmp", img);
	if (!img->texture[14])
		return (0);
	img->texture[15] = loadimage("../sprites/cell_button.bmp", img);
	if (!img->texture[15])
		return (0);
	img->texture[16] = loadimage("../sprites/health_button.bmp", img);
	if (!img->texture[16])
		return (0);
	img->texture[17] = loadimage("../sprites/key_button.bmp", img);
	if (!img->texture[17])
		return (0);
	ft_putendl("Ok load_objects");//DEBUG
	return (1);
}

short			loadmedia(t_fdf *img)
{
	if (load_textures(img) == 1 && load_objects(img) == 1)
	{
		ft_putendl("Ok loadmedia");//DEBUG
		return (1);
	}
	else
		return (0);
}
