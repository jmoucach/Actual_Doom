/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:12:48 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/03/11 11:21:27 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H

# include "../libft/libft.h"
//# include "/usr/local/include/SDL2/SDL.h"
//# include "/usr/local/include/SDL2/SDL_TTF.h"
//# include "/usr/include/SDL2/SDL.h"
//# include "/usr/include/SDL2/SDL_ttf.h"

# include <SDL.h>
# include <SDL_ttf.h>
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>//DEBUG
# include <math.h>

# define WIDTH 1600
# define HEIGHT 1200
# define NAME "MAP EDITOR"
# define OCRE 0xffa700
# define WHITE 0xf0f8ff
# define BROWN 0xcd7f32
# define GREEN 0x87a96b
# define SAND 0xfad6a5
# define LIGHT_BLUE 0xb2ffff
# define BLUE 0x21abcd
# define DEEP_BLUE 0x002fa7
# define RED 0xe32636
# define ZOOM_IN 1073741911
# define ZOOM_OUT 1073741910

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	SDL_Color		color;
}					t_point;

typedef struct		s_pt
{
	int				x;
	int				y;
} 					t_pt;

typedef struct		s_mouse
{
	int				posx;
	int				posy;
	int				click1[2];
	int				click;
	int				loop;
}					t_mouse;

typedef	struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				zoom_in;
	int				zoom_out;
}					t_key;

typedef struct		s_item
{
	SDL_Rect		rect;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_item;

typedef struct		s_txt
{
	t_item			*menu;
	t_item			*item;
	TTF_Font		*font;
	SDL_Rect		txt_through;
	SDL_Color		color;
}					t_txt;

typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				ox;
	int				oy;
	float			base_gap;
	float			base_h;
	char			proj;
	int				zmax;
	int				endx;
	int				endy;
}					t_map;

typedef struct		s_fdf
{
	char			*map_name;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*map_texture;
	SDL_Texture		**texture;
	SDL_Texture		*grid;//essai
	SDL_Texture		*text_texture;
	t_txt			*txt;
	t_map			*map;
	int				height;
	Uint32			*pixels;
	int				bpp;
	int				s_l;
	int				endian;
	int				*point_color;
	SDL_Color		color;
}					t_fdf;

typedef	struct		s_line
{
	char			*str;
	int				x;
	int				y;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef	struct		s_bres
{
	int				dx;
	int				dy;
	int				dz;
	int				i;
	int				xinc;
	int				yinc;
	int				error;
	int				x;
	int				y;
	int				z;
	int				col;
}					t_bres;

/*
**			PARSING
*/
t_map				*ft_parser(int fd);
t_map				*ft_map_copy(t_line *list);
t_line				*ft_list_alloc(int fd);
char				*ft_conform_line(char *str);
int					ft_conform_char(char c);

/*
**			INFINITE LOOP
*/
void				ft_fdf(t_map *map, char *map_name);

/*
**			INIT
*/
t_fdf				*ft_ptr_init(char *name);
t_map				*ft_map_init(t_line *list);
t_txt				*ft_txt_init(t_fdf *img);
int					ft_mouse_init(t_mouse *mous);
int					ft_key_init(t_key *key);
t_item				*ft_sub_init(TTF_Font *font, SDL_Color color,
		SDL_Renderer *renderer);
t_item				*ft_menu_init(TTF_Font *font, SDL_Color color,
		SDL_Renderer *renderer);
t_txt				*ft_txt_init(t_fdf *img);
void				nullify_textures(t_fdf *img);
short				loadmedia(t_fdf *img);

/*
**			FREE_FUNCTIONS
*/
void				ft_free_map(t_map *map);
void				ft_free_line(t_line *list);
void				ft_free_fdf(t_fdf *fdf);

/*
**			EVENT
*/
void				loop_til_release();
void				ft_menu_event(t_mouse *mous, SDL_Event e);
void				ft_keys_event(t_map *map, SDL_Event e, t_key *key);
void				ft_mouse_event(t_fdf *img, t_mouse *mous, SDL_Event e);
void				click_to_modify_map(t_map *map, t_mouse *mous);
void				ft_save_map(t_fdf *img);
/*
**			DRAW
*/
void				ft_clear_and_render(t_fdf *img, int	loop);
void				ft_print_grid(t_fdf *img);
void				ft_render_buttons(t_fdf *img);
void				ft_print_pressed_button(t_fdf *img, int i);
void				ft_print_blocks(int x, int y, int map_value,
		t_fdf *img, int size);
void				ft_parse_and_print_textures(t_fdf *img);
void				draw_line(t_pt pt_one, t_pt pt_two, Uint32 *pixels, int colour);
void				check_and_draw_line(t_pt start, t_pt end, t_fdf *img, int col);

/*
**			COLORS
*/
SDL_Color			ft_hexa_to_SDL(int color);

/*
**			MOVING
*/
void				ft_zoom(t_key *key, t_map *map);
void				ft_move(t_key *key, t_map *map);

/*
**			TOOLS
*/
int					ft_gap(t_map *map);
void				ft_origin(t_map *map);
float				ft_height(t_map *map);
void				ft_fix_coords(t_map *map, int *x, int *y);

#endif
