/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:57:32 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 17:19:57 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/doom_nukem.h"

/*
** TODO replace malloc sizes with fixed numbers
*/
static void	create_sprites_3(t_data *data)
{
	data->obj_sprite[24] = create_sprites("sprites/pickups/cell.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[25] = create_sprites("sprites/pickups/health_pu.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[26] = create_sprites("sprites/pickups/armor_pu.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[27] = create_sprites("sprites/pickups/key.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[28] = create_sprites("sprites/pickups/hud_key.bmp",
			(t_d_point){1, 1}, data);
}

static void	create_sprites_2(t_data *data)
{
	data->obj_sprite[12] = create_sprites("sprites/enemies/soul_walking_1.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[13] = create_sprites("sprites/enemies/soul_walking_2.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[14] = create_sprites("sprites/enemies/soul_attacking_1.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[15] = create_sprites("sprites/enemies/soul_attacking_2.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[16] = create_sprites("sprites/enemies/soul_dead_1.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[17] = create_sprites("sprites/enemies/soul_dead_2.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[18] = create_sprites("sprites/enemies/soul_dead_3.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[19] = create_sprites("sprites/enemies/soul_dead_4.bmp",
			(t_d_point){0.5, 0.5}, data);
	data->obj_sprite[20] = create_sprites("sprites/enemies/soul_dead_5.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[21] = create_sprites("pics/pillar.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[22] = create_sprites("sprites/pickups/bullets.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[23] = create_sprites("sprites/pickups/shells.bmp",
			(t_d_point){1, 1}, data);
}

static void	create_sprites_1(t_data *data)
{
	data->obj_sprite[0] = create_sprites("sprites/enemies/imp_walking_1.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[1] = create_sprites("sprites/enemies/imp_walking_2.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[2] = create_sprites("sprites/enemies/imp_walking_3.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[3] = create_sprites("sprites/enemies/imp_walking_4.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[4] = create_sprites("sprites/enemies/imp_attacking_1.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[5] = create_sprites("sprites/enemies/imp_attacking_2.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[6] = create_sprites("sprites/enemies/imp_attacking_3.bmp",
			(t_d_point){1, 1}, data);
	data->obj_sprite[7] = create_sprites("sprites/enemies/imp_dead_1.bmp",
			(t_d_point){1, 62.0 / 57.0}, data);
	data->obj_sprite[8] = create_sprites("sprites/enemies/imp_dead_2.bmp",
			(t_d_point){1, 59.0 / 57.0}, data);
	data->obj_sprite[9] = create_sprites("sprites/enemies/imp_dead_3.bmp",
			(t_d_point){1, 54.0 / 57.0}, data);
	data->obj_sprite[10] = create_sprites("sprites/enemies/imp_dead_4.bmp",
			(t_d_point){1, 46.0 / 57.0}, data);
	data->obj_sprite[11] = create_sprites("sprites/enemies/imp_dead_5.bmp",
			(t_d_point){1, 22.0 / 57.0}, data);
}

static void	alloc_data_structs(t_data *data)
{
	if (!(data->surface = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 9)))
		clean_exit(data, "Surface malloc error");
	nullify_tab((void**)data->surface, 9);
	if (!(data->obj_sprite = (t_sprite*)malloc(sizeof(t_sprite) * 29)))
		clean_exit(data, "Object sprite malloc error");
	nullify_sprites(data->obj_sprite, 20);
	if (!(data->zBuffer = (double *)malloc(sizeof(double) * SCREEN_WIDTH)))
		clean_exit(data, "ZBuffer malloc error");
}

void		set_values(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	nullify_mallocs(data);
	if (!(data->sprites = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * 33)))
		clean_exit(data, "Sprites malloc error");
	nullify_tab((void**)data->sprites, 33);
	data->p.dir.x = 1;
	data->toggle_minimap = 1;
	data->p.plane.y = -0.66;
	data->p.rspeed = 2;
	data->p.sprintspeed = 6;
	data->p.walkspeed = 3;
	data->p.hp = 100;
	data->p.armor = 25;
	data->p.bullets = MAX_BULLETS;
	data->p.shells = MAX_SHELLS;
	data->p.rockets = MAX_ROCKETS;
	data->p.cells = MAX_CELLS;
	data->p.has_fired = 1;
	data->mouse_sens = 1;
	alloc_data_structs(data);
	create_sprites_1(data);
	create_sprites_2(data);
	create_sprites_3(data);
}
