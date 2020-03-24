/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:50:44 by acostaz           #+#    #+#             */
/*   Updated: 2020/03/11 15:25:27 by acostaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

//# include "/Users/acostaz/.brew/include/SDL2/SDL.h"
//# include "/Users/acostaz/.brew/include/SDL2/SDL_TTF.h"
# include "/usr/local/include/SDL2/SDL.h"
# include "/usr/local/include/SDL2/SDL_ttf.h"
// # include "/usr/include/SDL2/SDL.h"
// # include "/usr/include/SDL2/SDL_ttf.h"
# include "struct.h"
# include "proto.h"
# include "../libft/inc/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# define MAX_BULLETS 200
# define MAX_SHELLS 16
# define MAX_CELLS 100
# define MAX_ROCKETS 8

# define BUFF_SIZE 4096

# define BFG 2.0
# define CHAINSAW 0.2
# define HANDGUN 0.6
# define KNUCKLE 0.3
# define MINIGUN 0.1
# define PLASMA 0.2
# define SHOTGUN 0.7

# define DYING 0
# define WALKING 1
# define ATTACKING 2
# define STUNNED 3

# define GROUND 0
# define FLOAT 1
# define ROOF 2

#endif
