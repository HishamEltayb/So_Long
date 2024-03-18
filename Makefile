# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 07:06:22 by heltayb           #+#    #+#              #
#    Updated: 2024/03/18 07:19:02 by heltayb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	mac_error_arguments.c mac_error_map.c mac_exit_functions.c \
		mac_image_movements.c mac_checking.c mac_image_move_player.c \
		mac_map_initilize.c mac_error_xpm_exit.c mac_player_movements.c \
		mac_map_read.c mac_error_map_path.c mac_error_characters.c mac_so_long.c

SRCS_LINUX = 	linux_error_arguments.c linux_error_map.c linux_exit_functions.c \
				linux_image_movements.c linux_checking.c linux_image_move_player.c \
				linux_map_initilize.c linux_error_xpm_exit.c linux_player_movements.c \
				linux_map_read.c linux_error_map_path.c linux_error_characters.c linux_so_long.c

LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ${SRCS:.c=.o}

#for Linux
MLX_LINUX = mlx_Linux/libmlx_Linux.a
PROGRAM_LINUX = so_long_linux
OBJECTS_LINUX = ${SRCS_LINUX:.c=.o}

#for MAC		
MLX = mlx/libmlx.a
NAME = so_long


all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX) 
	@$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJECTS) $(LIBFT) -Imlx -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	@make -C mlx
	
linux: $(PROGRAM_LINUX)

$(PROGRAM_LINUX): $(OBJECTS_LINUX) $(MLX_LINUX)
	@make -C libft
	@$(CC) $(CFLAGS) -g3 $(OBJECTS_LINUX) $(LIBFT) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(PROGRAM_LINUX)

$(MLX_LINUX):
	@make -C mlx_Linux

$(LIBFT):
	@make -C libft
	
clean:
	@-make clean -C libft
	@-rm -rf $(OBJECTS)
	@-rm -rf $(OBJECTS_LINUX)
	@-make clean -C mlx
	@-make clean -C mlx_Linux

fclean: clean
	@-rm -rf $(NAME)
	@-make fclean -C libft
	@-rm -rf $(PROGRAM_LINUX)

re:	fclean all

re_linux: fclean linux

.PHONY:	linux clean fclean all re re_linux
