NAME = fdf

SRC_PATH = src
SRC_NAME = fdf.c brezenhem.c window.c reader.c ../libft/srcs/get_next_line.c\
hook_init.c draw.c matrix_x.c matrix_y.c matrix_z.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -g -Wall -Werror -Wextra
CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of FdF:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c ./includes/fdf.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "FdF: Removing Objs"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "FdF: Removing FdF"

re: fclean all

.PHONY: all, clean, fclean, re
