# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 18:12:47 by juhur             #+#    #+#              #
#    Updated: 2022/07/04 20:51:21 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

INC_DIR = ./include

MLX_DIR = ./mlx
MLX_AR = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

DRAW_DIR = $(SRC_DIR)/draw
DRAW_SRCS = $(addprefix $(DRAW_DIR)/, \
	destroy.c \
	draw_raycasting.c \
	draw.c \
	texture.c \
)

EVENT_DIR = $(SRC_DIR)/event
EVENT_SRCS = $(addprefix $(EVENT_DIR)/, \
	key_hook.c \
	mouse_hook.c \
)

INIT_DIR = $(SRC_DIR)/init
INIT_SRCS = $(addprefix $(INIT_DIR)/, \
	init.c \
	mlx.c \
)

PARSE_DIR = $(SRC_DIR)/parse
PARSE_SRCS = $(addprefix $(PARSE_DIR)/, \
	background.c \
	check_map.c \
	image.c \
	map.c \
	parse.c \
	read.c \
)

QUIT_DIR = $(SRC_DIR)/quit
QUIT_SRCS = $(addprefix $(QUIT_DIR)/, \
	quit.c \
)

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	atoi.c \
	calloc.c \
	free.c \
	get_next_line.c \
	isspace.c \
	list.c \
	split.c \
	strchr.c \
	strcmp.c \
	strdup.c \
	strexpand.c \
	strlcat.c \
	strlen.c \
	strncmp.c \
	strndup.c \
)

SRC_DIR = ./src
ROOT_SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
)

SRCS = \
	$(DRAW_SRCS) \
	$(EVENT_SRCS) \
	$(INIT_SRCS) \
	$(PARSE_SRCS) \
	$(QUIT_SRCS) \
	$(UTIL_SRCS) \
	$(ROOT_SRCS) \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean : clean
	rm -f $(MLX_AR)
	rm -f $(NAME)

re : fclean all

$(MLX_AR) :
	make -C $(MLX_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

$(NAME) : $(OBJS) $(MLX_AR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(INC_DIR) $(MLX_AR) $^ -o $@

.PHONY : all, clean, fclean, re