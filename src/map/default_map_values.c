#include "../../hdr/doom_nukem.h"

static void	get_map1_values(t_data *data)
{
	ft_bzero(&(data->p), sizeof(t_player));
	data->ceiling = 1;
	data->shaded = 0;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->p.rspeed = 2;
	data->p.sprintspeed = 6;
	data->p.walkspeed = 3;
	data->p.hp = 1;
	data->p.armor = 25;
	data->p.bullets = MAX_BULLETS;
	data->p.shells = MAX_SHELLS;
	data->p.rockets = MAX_ROCKETS;
	data->p.cells = MAX_CELLS;
	data->p.has_fired = 1;
}

static void	get_map2_values(t_data *data)
{
	ft_bzero(&(data->p), sizeof(t_player));
	data->ceiling = 0;
	data->shaded = 1;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->p.rspeed = 2;
	data->p.sprintspeed = 6;
	data->p.walkspeed = 3;
	data->p.hp = 2;
	data->p.armor = 25;
	data->p.bullets = MAX_BULLETS;
	data->p.shells = MAX_SHELLS;
	data->p.rockets = MAX_ROCKETS;
	data->p.cells = MAX_CELLS;
	data->p.has_fired = 1;
}

static void	get_map3_values(t_data *data)
{
	ft_bzero(&(data->p), sizeof(t_player));
	data->ceiling = 0;
	data->shaded = 0;
	data->p.dir.x = 1;
	data->p.plane.y = -0.66;
	data->p.rspeed = 2;
	data->p.sprintspeed = 6;
	data->p.walkspeed = 3;
	data->p.hp = 3;
	data->p.armor = 25;
	data->p.bullets = MAX_BULLETS;
	data->p.shells = MAX_SHELLS;
	data->p.rockets = MAX_ROCKETS;
	data->p.cells = MAX_CELLS;
	data->p.has_fired = 1;
}

static void	get_custom_map_values(t_data *data)
{
	ft_bzero(&(data->p), sizeof(t_player));
	data->ceiling = 1;
	data->p.dir.x = 1;
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
}

void	get_map_values(t_data *data, short selected)
{
	data->yaw = 0;
	if (selected == 0)
		get_map1_values(data);
	if (selected == 1)
		get_map2_values(data);
	if (selected == 2)
		get_map3_values(data);
	if (selected == 3)
		get_custom_map_values(data);
}
