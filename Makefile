# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JP <JP@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 12:42:59 by acostaz           #+#    #+#              #
#    Updated: 2020/03/25 16:07:41 by JP               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD `sdl2-config --cflags` 

NAME = doom-nukem

LIBFT = libft/libft.a

SRC=	init/main.c\
		init/init.c\
		init/set_values.c\
		init/get_hud_text.c\
		init/nullify.c\
		draw/drawline.c\
		draw/display_hud.c\
		draw/draw_rect_to_sdl.c\
		draw/draw_minimap.c\
		draw/show_player.c\
		map/new_map.c\
		map/fill_map.c\
		map/default_map_values.c\
		map/parsing.c\
		menu/menu.c\
		menu/menu_selection.c\
		raycasting/raycasting.c\
		raycasting/floorcaster.c\
		raycasting/objectcasting.c\
		raycasting/set_objcast_values.c\
		story/display_story_screen.c\
		story/text_screen_inputs.c\
		game/health.c\
		game/ammo.c\
		game/combat.c\
		game/doors.c\
		game/event_loop.c\
		game/flashing_screens.c\
		game/movement.c\
		game/menu_inputs.c\
		game/weap_hits.c\
		image/load_image.c\
		image/load_media_hud.c\
		image/shading.c\
		skybox/skybox.c\
		weapon/use_weapon.c\
		weapon/use_knuckle.c\
		weapon/use_chainsaw.c\
		weapon/use_shotgun.c\
		weapon/use_plasma.c\
		weapon/use_bfg.c\
		weapon/use_handgun.c\
		weapon/use_minigun.c\
		objects/count_enemies.c\
		objects/pathfinder.c\
		objects/obj_list.c\
		objects/swap_obj.c\
		objects/get_obj_data.c\
		objects/state_machine.c\
		objects/item_pickup.c\
		objects/ammo_pickup.c\
		objects/hud_keys.c\
		objects/enemy_vision.c\
		exit/clean_exit.c

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = hdr/

SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ= $(SRC:.c=.o)
DPD= $(SRC:.c=.d)

OBJ_SUBDIRS= init draw map raycasting game image skybox weapon \
			 objects menu story exit
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))
LIB= `sdl2-config --libs` \
	 `sdl2-config --libs`_ttf\
	 -L libft -lft
INCLUDES=	hdr/doom_nukem.h\
			hdr/proto.h\
			hdr/struct.h

all: $(SUBDIRS)
	@$(MAKE) all -C libft
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@echo "\033[2K \033[A"
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT) -lm
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT)
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(SUBDIRS)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(OBJ_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(LIBFT)
	@echo "\033[31m[$(LIBFT)]: deleted\033[0m"
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

instalSDL:
	brew install SDL2

re : fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
