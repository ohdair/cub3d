# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 18:12:47 by juhur             #+#    #+#              #
#    Updated: 2022/06/29 14:52:51 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./include

INIT_DIR = $(SRC_DIR)/init
INIT_SRCS = $(addprefix $(INIT_DIR)/, \
	init.c \
)

QUIT_DIR = $(SRC_DIR)/quit
QUIT_SRCS = $(addprefix $(QUIT_DIR)/, \
	quit.c \
)

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	calloc.c \
	free.c \
	strcmp.c \
	strdup.c \
	strexpand.c \
	strlcat.c \
	strlen.c \
)

SRC_DIR = ./src
ROOT_SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
)

SRCS = \
	$(INIT_SRCS) \
	$(QUIT_SRCS) \
	$(UTIL_SRCS) \
	$(ROOT_SRCS) \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $^ -o $@

.PHONY : all, clean, fclean, re