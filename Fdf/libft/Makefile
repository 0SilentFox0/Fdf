# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 09:52:35 by aspizhav          #+#    #+#              #
#    Updated: 2018/10/29 09:52:38 by aspizhav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = srcs
SRC_NAME = ft_isalnum.c	ft_itoa.c		ft_memcpy.c	 ft_putchar_fd.c  ft_putstr.c\
	  ft_strcmp.c	ft_striter.c	ft_strmap.c	 ft_strnequ.c	  ft_strsub.c\
	  ft_isalpha.c  ft_memalloc.c	ft_memdel.c	 ft_putendl.c 	ft_putstr_fd.c\
	  ft_strcpy.c	ft_striteri.c	ft_strmapi.c ft_strnew.c    ft_strtrim.c\
	  ft_isascii.c  ft_memccpy.c	ft_memmove.c ft_putendl_fd.c ft_strcat.c\
 	  ft_strdel.c	ft_strjoin.c	ft_strncat.c ft_strnstr.c	ft_tolower.c\
ft_atoi.c	ft_isdigit.c	ft_memchr.c	ft_memset.c	ft_putnbr.c	ft_strchr.c\
ft_strdup.c	ft_strlcat.c	ft_strncmp.c	ft_strstr.c	ft_toupper.c\
ft_bzero.c	ft_isprint.c	ft_memcmp.c	ft_putchar.c	ft_putnbr_fd.c \
ft_strclr.c	ft_strequ.c	ft_strlen.c	ft_strncpy.c ft_lstnew.c ft_lstdelone.c\
ft_lstdel.c	ft_lstadd.c	ft_lstiter.c ft_lstmap.c ft_strsplit.c ft_strrchr.c\
ft_strrev.c ft_list_reverse.c ft_isprime.c ft_sqrt.c ft_print_memory.c\
ft_atoi_base.c int_len.c get_next_line.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation of Libft:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Libft: Removing Objs"

fclean: clean
	@rm -f $(NAME)
	@echo "Libft: Removing Libft"

re: fclean all

.PHONY: all, clean, fclean, re
