/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:07:29 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:22:55 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_SO_LONG_H
# define LINUX_SO_LONG_H

# include "mlx_Linux/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_chars
{
	int		collect;
	int		exit;
	int		player;
}	t_chars;

typedef struct s_data
{
	char	**map;
	char	**map_copy;
	void	*connection;
	void	*window;
	void	*wall;
	void	*player_left;
	void	*player_right;
	int		player_direction;
	void	*grass;
	void	*coins;
	void	*exit;
	int		number_of_coins;
	int		steps;
	int		width;
	int		height;
	int		pixel;
	int		is_valid;
	int		player_height;
	int		player_width;
	int		player_on_exit;
}	t_data;

//error related to arguments and maps (error_arguments.c)
void	error_split(char *join);
void	error_short_arguments(void);
void	error_too_much_arguments(void);
void	error_map_not_valid(char **split);
void	error_joining(char *str, char *temp);

//error related to map path (error_map_path.c)
void	error_newline(char **split);
void	error_map_walls(char **split);
void	error_map_invalid_path(char **split);
void	error_map_bigger_than_screen(char **split);

//error related to map (error_map.c)
void	error_map_read(char *str);
void	error_map_not_found(void);
void	error_map_empty(char *str);
void	error_map_wrong_name(void);
void	error_map_not_rectangular(char **split);

//errors for characters (error_characters.c)
void	error_more_than_exit(char **split);
void	error_more_than_player(char **split);
void	error_no_collectables(char **split);

//exititing via mouse, keyboard and win (exit_functions.c)
int		is_valid_char(char c);
void	exit_win(t_data *mlx);
int		exit_mouse(t_data *mlx);
void	error_xpm_exit(t_data *mlx);
int		exit_key(int key, t_data *mlx);

//movement of the image depends on the player position (image_move_player.c)
void	player_on_exit_move(t_data *mlx, int height, int width);
void	player_not_on_exit_move(t_data *mlx, int height, int width);
void	putting_image_to_window(t_data *mlx, int height, int width);

//moving the image and game initilize (image_movements.c)
int		render(t_data *mlx);
int		move_image(int key, t_data *mlx);
void	movements(int key, int height, int width, t_data *mlx);
void	movements_of_player(int key, int flag, t_data *mlx);

//map_initilize and helping functions (map_initilize.c)
int		number_of_coins(t_data *mlx);
int		check_map_rectangular(t_data *mlx);
void	map_initilize(char *arg, t_data *mlx);

//reading the map (map_read.c)
char	*read_map(char *arg);
void	free_split(char **str);
void	check_walls(t_data *mlx);
void	check_map_name(char *arg);
char	*parsing_the_map(int fd, char **join);

//player movements functions (player_movements.c)
void	print_steps(int steps);
void	movement_up(int height, int width, t_data *mlx);
void	movement_left(int height, int width, t_data *mlx);
void	movement_down(int height, int width, t_data *mlx);
void	movement_right(int height, int width, t_data *mlx);

//the main file contain the main function (so_long.c)
int		main(int ac, char **av);
void	game_initilize(t_data *mlx);
void	image_initilize(t_data *mlx);
void	validpath(t_data *mlx, int x, int y);
int		is_validpath(t_data *mlx, int x, int y);

//checking functions (checking.c)
int		check_join(char *str);
void	check_chars_validaty(int height, int width,
			t_chars *x, t_data *mlx);

//error for xpm files not found (error_xpm_exit.c)
void	error_xpm_wall(t_data *mlx);
void	error_xpm_grass(t_data *mlx);
void	error_xpm_player_left(t_data *mlx);
void	error_xpm_collectables(t_data *mlx);
void	error_xpm_player_right(t_data *mlx);

#endif