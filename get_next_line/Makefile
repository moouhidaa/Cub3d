SOURCE = get_next_line.c  get_next_line_utils.c
CC  = cc
FLAGS =  -Wall -Wextra -Werror 

NAME = cub3D

OBJ = $(SOURCE:%.c=%.o)

%.o:%.c 
	cc $(FLAGS) -c $< -o $@
	
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) 

all:$(NAME)

clean:
	@rm -rf  $(OBJ)

fclean: clean
	@rm -rf $(OBJ) $(NAME)

re : fclean  all

.PHONY :all  clean  fclean re