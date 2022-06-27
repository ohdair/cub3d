# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 18:12:47 by juhur             #+#    #+#              #
#    Updated: 2022/06/27 18:30:38 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./include

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	strcmp.c \
	strlen.c \
)

SRC_DIR = ./src
ROOT_SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
)

SRCS = \
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