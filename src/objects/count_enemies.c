#include "../../hdr/doom_nukem.h"

short	count_enemies(t_data *data)
{
	short		count;
	t_object	*iterator;

	count = 0;
	if (data->obj)
	{
		rollback_object(&data->obj);
		iterator = data->obj;
		while (iterator)
		{
			if (iterator->obj_type == 0
					|| iterator->obj_type == 1
					|| iterator->obj_type == 2)
				count++;
			iterator = iterator->next;
		}
	}
	return (count);
}
