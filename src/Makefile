NAME = cub3D

CC = cc

CCFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

GNL_FILES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MEM_FILES = mem_collector/mem_collector.c

UTILS_FILES = ft_isspace.c ft_memset.c ft_putstr_fd.c ft_strcmp.c  ft_strlen.c ft_strrchr.c \
ft_split.c ft_memcpy.c ft_itoa.c $(GNL_FILES) $(MEM_FILES)

PARSING_FILES = parser/parser_1.c parser/parser_2.c parser/parser_3.c parser_utils.c textures/textures_1.c textures/textures_2.c \
			    map/map_1.c  map/map_2.c map/map_3.c map/map_4.c colors/colors_1.c colors/colors_2.c  memory.c textures/textures.c

RAYCASTING_FILES = raycasting/raycasting.c raycasting/ray_init.c raycasting/ray_dda.c raycasting/ray_texture.c raycasting/ray_draw.c \
			raycasting/player.c raycasting/player_init.c raycasting/player_move.c raycasting/collision.c  \
			raycasting/window.c raycasting/window_loop.c raycasting/window_loop2.c

UTILS = $(addprefix utils/,$(UTILS_FILES))
PARSING = $(addprefix parsing/,$(PARSING_FILES))

CUBSRC = raycasting/cub3d.c $(RAYCASTING_FILES)

FILES = $(CUBSRC) $(UTILS) $(PARSING)

SRCFILES = $(addprefix src/,$(FILES))

OBJS = $(SRCFILES:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME) : $(OBJS) $(MLX_LIB)
	$(CC) $(CCFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)


%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean 2>/dev/null || true

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean 2>/dev/null || true

re: fclean all

.PHONY: all clean fclean re
