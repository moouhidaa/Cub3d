
SOURCE =  main.c libft/ft_memset.c libft/ft_atoi.c  libft/ft_strlen.c   libft/ft_strjoin.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_isalpha.c\
		  libft/ft_lstclear_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_isdigit.c \
		  execution/load_img_addr.c execution/normalize.c\
		  libft/ft_strchr.c libft/ft_strncmp.c libft/ft_strdup.c\
		  libft/ft_substr.c libft/ft_strlcpy.c libft/ft_strtrim.c\
		  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c execution/start_simulation.c\
		  execution/find_xy_axis.c execution/raycasting.c execution/destroy_win.c execution/rendering_textures.c\
		  execution/picture_to_xpm.c execution/get_color_and_other.c execution/run_the_game.c\
		  parsing/extract_rgb.c   parsing/ft_realloc.c parsing/gc_malloc.c  parsing/get_paths.c  parsing/init_player.c\
		  parsing/pars_path.c parsing/space_rounded.c  parsing/usual_functions.c  parsing/valid_map.c\
		  parsing/find_pp.c parsing/pars_map.c 

CC  = cc
FLAGS =  -Wall -Wextra -Werror 

FLAGS_MLX_LIB = -L  minilibx/minilibx-linux  -lmlx -lXext -lm -lX11 

NAME = cub3D

OBJ = $(SOURCE:%.c=%.o)

%.o:%.c 
	cc $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJ)  include/cub3d.h
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)  $(FLAGS_MLX_LIB) 

all:$(NAME)

clean:
	@rm -rf  $(OBJ)

fclean: clean
	@rm -rf $(OBJ) $(NAME)
	@make -C libft fclean

re : fclean  all

.PHONY :all  clean  fclean re
