# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 22:26:19 by mporras-          #+#    #+#              #
#    Updated: 2022/07/08 12:53:04 by msoler-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES		=	boxes.c \
					ft_checks.c \
					ft_clean_mem.c \
					ft_load_data.c \
					ft_perms.c \
					ft_queue.c \
					ft_solver.c \
					string_utl.c
HEADER_DIR		=	includes
HEADER			=	ft_boxes.h
SRCS_DIR		=	srcs
OBJS_DIR		=	obj
SRCS 			=	$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.cpp=.o))
CC				=	gcc
RM				= 	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	boxes

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I$(HEADER_DIR) $(CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(OBJS_DIR):
	-mkdir $(OBJS_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS_DIR)

re:	fclean $(OBJS_DIR) $(NAME)

.PHONY: all clean fclean re
