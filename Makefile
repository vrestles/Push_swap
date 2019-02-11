# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrestles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 13:37:59 by vrestles          #+#    #+#              #
#    Updated: 2019/02/05 13:38:01 by vrestles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = both

NAME_PUSHSWAP = push_swap
NAME_CHECKER = checker

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes/

SRC_PUSHSWAP = push_swap/push_swap.c \
	push_swap/instructions_void.c \
	push_swap/math.c \
	push_swap/optimization.c \
	push_swap/other_sort.c \
	push_swap/pivot_functions.c \
	push_swap/quick_sort.c \
	push_swap/sort_a_stack.c \
	push_swap/sort_b_stack.c \
	push_swap/sort_functions.c

SRC_CHECKER = checker/checker.c \
	checker/apply_commands.c

SRC_COMMON = common/asc_desc.c \
	common/instructions_int.c \
	common/stack_operations.c \
	common/valid_check.c

OBJ_PUSHSWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSHSWAP:.c=.o))
OBJ_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))
OBJ_COMMON = $(addprefix $(OBJ_DIR)/, $(SRC_COMMON:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = src/libft/libft.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/common
	@mkdir -p $(OBJ_DIR)/push_swap
	@mkdir -p $(OBJ_DIR)/checker

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_COMMON) $(OBJ_PUSHSWAP) $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP) $(OBJ_COMMON) -o $(NAME_PUSHSWAP) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_CHECKER) $(OBJ_COMMON) -o $(NAME_CHECKER) $(LIBFT)

$(NAME_PUSHSWAP): $(LIBFT) $(OBJ_DIR) $(OBJ_COMMON) $(OBJ_PUSHSWAP)
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP) $(OBJ_COMMON) -o $(NAME_PUSHSWAP) $(LIBFT)

$(NAME_CHECKER): $(LIBFT) $(OBJ_DIR) $(OBJ_COMMON) $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(OBJ_CHECKER) $(OBJ_COMMON) -o $(NAME_CHECKER) $(LIBFT)

$(OBJ_PUSHSWAP): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(OBJ_CHECKER): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(OBJ_COMMON): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	@make -C ./src/libft/

clean:
	@rm -f $(OBJ_PUSHSWAP) $(OBJ_CHECKER) $(OBJ_COMMON)
	@rm -rf $(OBJ_DIR)
	@make clean -C ./src/libft/

fclean: clean
	@rm -f $(NAME_PUSHSWAP) $(NAME_CHECKER)
	@make fclean -C ./src/libft

re: fclean all
