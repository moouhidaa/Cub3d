NAME		= cub3d

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -O2
MLX_DIR		= mlx_linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES	= -I. -I$(MLX_DIR)

SRC_DIR		= src
UTIL_DIR	= utils

SRCS		= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/parsing/parse_file.c \
		  $(SRC_DIR)/parsing/parse_config.c \
		  $(SRC_DIR)/parsing/parse_map.c \
		  $(SRC_DIR)/parsing/validate_map.c \
		  $(SRC_DIR)/rendering/render.c \
		  $(SRC_DIR)/rendering/draw.c \
		  $(SRC_DIR)/player/movement.c \
		  $(SRC_DIR)/player/input.c \
		  $(UTIL_DIR)/ft_utils.c \
		  $(UTIL_DIR)/error.c

OBJS		= $(SRCS:.c=.o)

MLX_LIB		= $(MLX_DIR)/libmlx.a

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
