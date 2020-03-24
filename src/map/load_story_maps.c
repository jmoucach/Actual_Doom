#include "../../hdr/doom_nukem.h"

void	free_story_map(t_map *map, int size)
{
	while (--size >= 0)
		free(map->map[size]);
	free(map->map);
}

short	load_map_3(t_map *map)
{
	int	i;

	i = -1;
	map->width = 10;
	map->height = 10;
	if (!(map->map = (int**)malloc(sizeof(int*) * map->height)))
		return (0);
	while (++i < map->height)
		if (!(map->map[i] = (int*)malloc(sizeof(int) * map->width)))
			return (0);
	map->map[0] = (int*)ft_memcpy(map->map[0], (int[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[1] = (int*)ft_memcpy(map->map[1], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[2] = (int*)ft_memcpy(map->map[2], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[3] = (int*)ft_memcpy(map->map[3], (int[10]){1, 0, 'P', 0, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[4] = (int*)ft_memcpy(map->map[4], (int[10]){1, 0, 0, 0, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[5] = (int*)ft_memcpy(map->map[5], (int[10]){1, 0, 0, 0, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[6] = (int*)ft_memcpy(map->map[6], (int[10]){1, 0, 0, 0, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[7] = (int*)ft_memcpy(map->map[7], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[8] = (int*)ft_memcpy(map->map[8], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[9] = (int*)ft_memcpy(map->map[9], (int[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	return (1);
}

short	load_map_2(t_map *map)
{
	int	i;

	i = -1;
	map->width = 10;
	map->height = 10;
	if (!(map->map = (int**)malloc(sizeof(int*) * map->height)))
		return (0);
	while (++i < map->height)
		if (!(map->map[i] = (int*)malloc(sizeof(int) * map->width)))
			return (0);
	map->map[0] = (int*)ft_memcpy(map->map[0], (int[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[1] = (int*)ft_memcpy(map->map[1], (int[10]){1, 'P', 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[2] = (int*)ft_memcpy(map->map[2], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[3] = (int*)ft_memcpy(map->map[3], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[4] = (int*)ft_memcpy(map->map[4], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[5] = (int*)ft_memcpy(map->map[5], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[6] = (int*)ft_memcpy(map->map[6], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[7] = (int*)ft_memcpy(map->map[7], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[8] = (int*)ft_memcpy(map->map[8], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[9] = (int*)ft_memcpy(map->map[9], (int[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->width = 10;
	map->height = 10;
	return (1);
}

short	load_map_1(t_map *map)
{
	int	i;

	i = -1;
	map->width = 10;
	map->height = 10;
	if (!(map->map = (int**)malloc(sizeof(int*) * map->height)))
		return (0);
	while (++i < map->height)
		if (!(map->map[i] = (int*)malloc(sizeof(int) * map->width)))
			return (0);
	map->map[0] = (int*)ft_memcpy(map->map[0], (int[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->map[1] = (int*)ft_memcpy(map->map[1], (int[10]){1, 'P', 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[2] = (int*)ft_memcpy(map->map[2], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[3] = (int*)ft_memcpy(map->map[3], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[4] = (int*)ft_memcpy(map->map[4], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[5] = (int*)ft_memcpy(map->map[5], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[6] = (int*)ft_memcpy(map->map[6], (int[10]){1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[7] = (int*)ft_memcpy(map->map[7], (int[10]){1, 0, 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[8] = (int*)ft_memcpy(map->map[8], (int[10]){1, 'E', 0, 0, 1, 1, 0, 0, 0, 1}, 10 * sizeof(int));
	map->map[9] = (int*)ft_memcpy(map->map[9], (int[10]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10 * sizeof(int));
	map->width = 10;
	map->height = 10;
	return (1);
}

short	load_story_maps(t_data *data)
{
	load_map_1(&(data->maps[0]));
	load_map_2(&(data->maps[1]));
	load_map_3(&(data->maps[2]));
	return (1);
}
