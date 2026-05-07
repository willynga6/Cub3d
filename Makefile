
NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -Iget_next_line

OBJ_DIR = obj

# ALL DIRECTORIES CONTAINING SOURCE FILES #

CLEANDIR = clean
PARSINGDIR = parsing
TOOLSDIR = tools
GNL = get_next_line

SRCS = main.c \
	$(TOOLSDIR)/tools1.c \
	$(PARSINGDIR)/check_extension.c \
	$(PARSINGDIR)/check_the_mapfile_format.c \
	$(PARSINGDIR)/init_parsing.c \
	$(GNL)/get_next_line.c \
	$(GNL)/get_next_line_utils.c \
	$(CLEANDIR)/malloc.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all



