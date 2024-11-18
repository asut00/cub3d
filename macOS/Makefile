# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 12:33:11 by thelaine          #+#    #+#              #
#    Updated: 2024/07/28 17:27:48 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

FILES = src

SRC = 	cub3d.c\
		ft_calloc.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_substr.c\
		ft_putchar_fd.c\
		ft_strlcat.c\
		ft_strcmp.c\
		ft_isdigit.c\
		memory_management.c\
		check_args.c\
		map_error.c\
		map_error_2.c \
		split_information.c \
		read_map.c\
		ft_split_map.c\
		check_rgb.c\
		check_map_component.c\
		set_player_info.c \
		pixel_management.c\
		minimap.c\
		moves.c\
		ray_casting.c\
		get_texture.c \
		doors.c \

SRC_MANDATORY = $(SRC) \
				game_init.c \
				signal_handlers.c \
				weapon.c \
				game_error.c

SRC_BONUS =	$(SRC) \
			game_init_bonus.c \
			signal_handlers_bonus.c \
			weapon_bonus.c \
			game_error_bonus.c

VPATH		= src src/libft_spe src/garbage_collector src/check_args \
			src/parsing src/position_management src/game/minimap \
			src/game/ src/pixel_management src/game_error src/signals \
			src/game/doors bonus

INCL_DIR	=	include/

OBJECTS = $(SRC_MANDATORY:%.c=$(OBJ_DIR)/%.o)

OBJECTS_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR		=	build

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

# INCLUDES = -I ./minilibx
# LDFLAGS = -L /usr/local/lib -L libmlx_Linux -L ./minilibx
# LIBS = -lmlx -lX11 -lXext -lm
LINKS = -I /usr/local/include -I libft -I ./minilibx -L /usr/local/lib -L libft -lft -lmlx -framework OpenGL -framework Appkit

# ---------------------------------- RULES ----------------------------------- #

.c.o:
	$(CC) $(CFLAGS) -I $(INCL_DIR) $(INCLUDES) -c $< -o $(<:.c=.o)
# $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INCL_DIR) $(INCLUDES) $(OBJECTS) $(LINKS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:		%.c
				$(CC) $(CFLAGS) -I $(INCL_DIR) $(INCLUDES) -c $< -o $@

$(NAME_BONUS): $(OBJ_DIR) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) -I $(INCL_DIR) $(INCLUDES) $(OBJECTS_BONUS) $(LINKS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)
	rm -f -r $(OBJ_DIR)


fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

# minilibx:
# 	$(MAKE) -C minilibx

re: fclean all

norm:
	norminette $(FILES) $(INCL_DIR) bonus

.PHONY: all clean fclean re minilibx bonus
