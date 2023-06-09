SRC = cube.c exit.c projection.c update_map.c player_info.c move.c init.c parse.c texture.c tools.c
BIN = objs
OBJ = $(SRC:%.c=${BIN}/%.o)
NAME = cub3D
HEADERS = cube.h
FLAGS = -Wall -Werror -Wextra -g -fPIE -flto
FSAN = -fsanitize=address
LIBFT = ./libft/libft.a
MLX = ./mlx_linux/libmlx.a
LIBCOM = -C ./libft --no-print-directory
RM = rm -rf
CC = cc

#Colors
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

all : $(NAME)

$(NAME) : $(BIN) $(OBJ) | $(LIBFT) $(MLX)
	@$(CC) $(OBJ) $(FLAGS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lm -lz -lXext -lX11 -o $(NAME)
	@echo "$(GREEN)>>>> Compiled <<<<$(END)"

$(LIBFT) :
	@make $(LIBCOM)
	@make clean $(LIBCOM)

$(MLX) :
	make -C ./mlx_linux --no-print-directory

$(BIN) :
	@mkdir -p $(BIN)

$(BIN)/%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

valgrind :  $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) map1.cub

clean :
	@$(RM) $(BIN)
	@echo "$(RED)>>>> Cleaned <<<<$(END)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)>>>> All <<<<$(END)"

libclean : 
	@make fclean $(LIBCOM)

re : fclean all

.PHONY : all clean fclean re libclean