NAME := so_long
OBJ := ./obj
SRCDIR := .
SRCS := counters_and_setters.c dear_norm.c file_pars_utils.c ft_split.c ft_split_utils.c get_next_line.c get_next_line_utils.c graphics.c graphics_2.c join_lines.c main.c  map_checks.c useful_garbage.c w_a_s_d_x.c trim_nl.c trim_utils.c
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJ)/%.o, $(SRCS))
INCS := -I./libprintf  
HEADER := so_long.h
RM := rm -rf
CC := cc
FLAGS := -Wall -Wextra -Werror #-g3 -fsanitize=address
LINKERS := -lmlx -framework OpenGL -framework AppKit -L./libprintf -lftprintf 

all: $(NAME)

$(OBJ)/%.o: $(SRCDIR)/%.c $(HEADER)
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS) | $(OBJ)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LINKERS)

$(OBJ):
	mkdir -p $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
