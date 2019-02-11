# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrestles <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 20:51:58 by vrestles          #+#    #+#              #
#    Updated: 2019/02/04 17:13:38 by vrestles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR = includes/
OBJ_DIR = obj

SRC = ft_atoi.c \
	ft_is_number.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_straddchar.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_arrdel.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strnew.c \
	ft_strclr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	get_next_line.c \
	ft_count_words.c \
	ft_memalloc.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
