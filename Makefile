# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 11:36:10 by bsantana          #+#    #+#              #
#    Updated: 2024/04/19 16:04:01 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors to print message
GREEN := \033[1;32m
WHITE := \033[1;37m

# Executable name
NAME = push_swap

# Flags
CC = cc
CFLAGS =  -O3 -g3 -Wextra -Werror -Wall

# Files
SRC_DIR = src

# Source directory where .c files are located
FILES_SRC = checks.c error.c utils.c main.c stack.c stack_utils.c swap.c push.c rotate.c reverse_rotate.c \
sort_tiny.c sort.c cost.c position.c algorithm_operations.c moves.c

# List of object files derived from source files
FILES_SRC_O = $(FILES_SRC:.c=.o)

# List of header files directories
HEADERS_FILE = ./inc/push_swap.h

# Get the list of source files with the correct path
SRCS = $(addprefix $(SRC_DIR)/, $(FILES_SRC))
OBJS = ${addprefix $(SRC_DIR)/, $(FILES_SRC_O)}

# Compiles project mandatory
all: $(NAME)

# Compile .c file into .o file
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

# Build the final executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Push_swap successfully compiled!"

# Clean object files
clean:
	@rm -rf $(OBJS)

# Clean everything ((including the executable)
fclean: clean
	@rm -rf $(NAME)
	@echo "$(WHITE)Cleaning - PUSH_SWAP - completed!"

# Clean and rebuild everything
re: clean all

# Targets that are not associated with files
.PHONY: all, clean, fclean, re