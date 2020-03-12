# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 14:02:55 by jpoulvel          #+#    #+#              #
#    Updated: 2020/03/04 22:27:44 by jpoulvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map_editor

SRCS = srcs/main.c \
		srcs/draw/draw_menu.c \
		srcs/draw/draw_blocks.c \
		srcs/draw/print_grid.c \
		srcs/draw/render.c \
		srcs/event/infinite_loop.c \
		srcs/event/keys_controls.c \
		srcs/event/menu_controls.c \
		srcs/event/modify_map.c \
		srcs/event/mouse_controls.c \
		srcs/event/save_new_map.c \
		srcs/parsing/check_map.c \
		srcs/parsing/map_copy.c \
		srcs/parsing/parsing.c \
		srcs/tools/cart_to_iso.c \
		srcs/tools/colorize.c \
		srcs/tools/color_negative_positive.c \
		srcs/tools/fix_coords.c \
		srcs/tools/free_functions.c \
		srcs/tools/GNL_incoming_map.c \
		srcs/tools/change_appearance.c \
		srcs/init/center_map.c \
		srcs/init/mouse_and_key_init.c \
		srcs/init/surfaces_init.c \
		srcs/init/structures_init.c \
		srcs/init/text_init.c \
		srcs/textures/load_textures.c

OBJ = $(SRCS:.c=.o)

LIB_DIR = libft

INCL = map_editor.h \
	   $(LIB_DIR)/libft.a \
	   	#-I./frameworks/SDL2.framework/Versions/A/Headers \
	   -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
	   -I./frameworks/SDL2_image.framework/Versions/A/Headers \
	   -I./frameworks/SDL2_mixer.framework/Headers \
	   -I./frameworks/SDL2_net.framework/Headers \
	   -F./frameworks

FLAGS = -Wall -Wextra -Werror -I $(INCL) $(MLXFLAGS)

SDLFLAGS = -lSDL2-2.0.0  -lSDL2_ttf-2.0.0 `sdl2-config --cflags --libs`

FRAMEWORKS = -F./frameworks \
			 -rpath ./frameworks \
			 -framework OpenGL -framework AppKit -framework OpenCl \
			 -framework SDL2 -framework SDL2_ttf -framework SDL2_image \
			 -framework SDL2_mixer -framework SDL2_net

CC = clang -g

all: Makefile $(NAME)

$(NAME): FORCE LIB $(OBJ)
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(SDLFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(SDLFLAGS)
	@echo $<

LIB:
	@$(MAKE) -C $(LIB_DIR)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean $(NAME)

san : FORCE LIB $(OBJ)
	@gcc -o $(NAME) -fsanitize=address $(FLAGS) $(OBJ) $(SDLFLAGS)

FORCE:

.PHONY: all clean fclean re FORCE
