/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:57:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:42:39 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <X11/X.h>
# include <math.h>

# define MINIMAP_CENTER 80
# define SIZE_PLAYER 5
# define SIZE_MINIMAP 70
# define SIZE_SQUARE 20
# define OUT_OF_MAP 0x00545348
# define EMPTY_COLOR 0x00DAD3A8
# define PLAYER_COLOR 0x00A29966
# define DOORS_COLOR 0x0077670E
# define WALL_COLOR 0x00C6B763
# define ARG_NBR 7

# define W 800
# define H 600

# define NBR_OF_TEXTURES 6
# define NBR_OF_TEXTURES_BONUS 10

# define MOVE 0.1

# define KEY_ESC 0xff1b
# define KEY_W 'w'
# define KEY_A 'a'
# define KEY_S 's'
# define KEY_D 'd'
# define KEY_LEFT_ARR 0xff51
# define KEY_RIGHT_ARR 0xff53
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_E 'e'
# define KEY_SPACE ' '

# define HITBOX 0.10

# define F 0
# define C 1

# define DOOR_FILE "./textures/door.xpm"
# define GLOVES_FILE "./textures/hands.xpm"
# define GUN_0_FILE "./textures/gun_0.xpm"
# define GUN_1_FILE "./textures/gun_1.xpm"
# define GUN_2_FILE "./textures/gun_2.xpm"
# define GUN_3_FILE "./textures/gun_3.xpm"
# define GUN_4_FILE "./textures/gun_4.xpm"

# define WEAPON_X 350
# define WEAPON_Y 362
# define WEAPON_SPECIAL_Y 332
# define HANDS_X 100
# define HANDS_Y 130

# define RGB_INFO_NBR 2

typedef struct s_map
{
	char	**map;
	int		max_col;
	int		max_row;
}	t_map;

typedef struct s_textures
{
	char	*data;
	int		exist;
	void	*img;
	int		length;
	int		height;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_l;
}	t_textures;

typedef struct s_colors
{
	char	*data;
	int		exist;
	int		rgb[3];
	int		value;

}	t_colors;

typedef struct s_garbage
{
	void				*content;
	struct s_garbage	*next;
}	t_garbage;

typedef enum e_move
{
	FORWARD = 1,
	BACKWARD = -1,
	RIGHT = 1,
	LEFT = -1,
}	t_move;

typedef enum e_def
{
	NO,
	SO,
	WE,
	EA,
	DOOR,
	GUN_0,
	GUN_1,
	GUN_2,
	GUN_3,
	GUN_4,
	GLOVES= 5,
}	t_def;

typedef enum e_rgb
{
	R,
	G,
	B,
	RGB_NBR,
	RGB_MAX = 255,
	NBR_INT_MAX_RGB = 3,
}	t_rgb;

typedef struct s_vect{
	double	x;
	double	y;
}	t_vect;

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

typedef struct s_player_info {
	t_vect	dir;
	t_vect	ndir;
	t_vect	pos;
}	t_player_info;

typedef struct s_ray
{
	t_vect		raydir;
	t_vect		dist_side;
	t_vect		step;
	t_vect		deltadist;
	t_coord		map;
	double		wall_x;
	int			text_x;
	int			line_height;
	int			start;
	int			end;
	int			side;
	int			color;
	double		wall_dist;
	double		camx;
	int			hit;
	t_textures	*texture;
}	t_ray;

typedef struct s_var {
	t_garbage		*garbage_collector;
	t_textures		textures[NBR_OF_TEXTURES_BONUS];
	t_colors		colors[2];
	t_map			map;
	t_player_info	player_info;
	char			*file;
	char			**splitted_info;
	char			*path;
	int				player;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				zoom;
	int				mouse_move_last_x;
	int				shooting;
}	t_var;

//read_map.c
void	no_map_error(t_var *var);
void	read_file(t_var *var);

//map_error.c
void	not_enough_arg_error(t_var *var);
void	double_error(t_var *var);
void	rgb_error(t_var *var);
void	texture_error(t_var *var);
void	dimension_error(t_var *var);

// void	hole_error(t_var *var);
void	border_error(t_var *var);
void	char_error(char unexpected, t_var *var);
void	map_config_error(t_var *var);

//split_information.c
void	split_information(t_var *var);

//check_rgb.c
void	check_rgb(t_var *var);

//set_player_info.c
void	set_player_info(int row_nbr, int col_nbr, char dir, t_var *var);

//check_map.c
// int		is_empty_char(char c);
void	check_map_component(t_var *var);

//pixel_management.c
void	ft_pput(t_var *var, int x, int y, int color);
void	ft_draw_ceiling(t_var *var, int x, int end);
void	ft_draw_floor(t_var *var, int x, int start);

//minimap.c
void	zoom_minimap(t_var *var);
void	dezoom_minimap(t_var *var);
void	ft_draw_minimap(t_var *var);

//doors.c
void	try_opening_doors(t_var *var);

//libft_spe
void	*ft_calloc(int nb_elem, int size_elem, t_var *var);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c, t_var *var);
char	**ft_split_map(char *s, char c, t_var *var);
int		ft_strlcpy(char *dest, const char *src, int n);
int		ft_strlen(const char *str);
char	*ft_substr(char const *str, int start, int len, t_var *var);
int		ft_strlcat(char *dest, const char *src, int n);
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_isdigit(char c);

//check_args.c
void	check_args(int ac, char **av, char **envp);

//garbage management
void	ft_free(void *content_to_find, t_var *var);
void	clear_garbage_and_exit(t_var *var, int exit_value);
void	*ft_malloc(int size, t_var *pvar);

//signal_handlers
int		handle_keyboard(int keysym, t_var *data);
int		handle_mouse(int x, int y, t_var *var);
void	rotate(t_var *var, double angle);

//moves.c
void	move_straight(t_var *var, t_move move);
void	straf(t_var *var, t_move move);
int		is_collision(double x, double y, t_var *var);

//game_init.c
void	game_init(t_var *var);

//ray_casting.c
void	do_raycast(t_var *var, int gun);
void	ft_draw_weapon(t_var *var, int gun);

//get_textures.c
void	get_ver_line(t_ray *ray, t_var *var, int x);

// //game_error.c
void	mlx_creation_error(t_var *var);
void	window_creation_error(t_var *var);
void	img_creation_error(t_var *var);
void	data_addr_creation_error(t_var *var);
int		rage_quited(t_var *var);

#endif
