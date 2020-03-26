#include "../../hdr/doom_nukem.h"

void	handle_text_screen_input(t_data *data, const Uint8 *state)
{
	if (state[SDL_SCANCODE_ESCAPE])
		data->quit = 1;
	if (state[SDL_SCANCODE_SPACE])
	{
		if (data->enter_screen)
			data->enter_screen = 0;
		if (data->exit_screen || data->death_screen)
		{
			data->exit_screen = 0;
			data->death_screen = 0;
			data->menu = 1;
		}
	}
}
