
NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincludes -Iget_next_line

OBJ_DIR = obj

# ALL DIRECTORIES CONTAINING SOURCE FILES #

CLEANDIR = clean
PARSINGDIR = parsing
# PARING SUBDIRECTORIES #
CHECK_FILE_FORMAT = check_file_format
CHECK_MAP = check_map
INIT_PARSING = init_parsing
TOOLSDIR = tools
GNL = get_next_line

SRCS = main.c \
	$(TOOLSDIR)/tools1.c \
	$(TOOLSDIR)/tools2.c \
	$(TOOLSDIR)/tools3.c \
	$(PARSINGDIR)/check_extension.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format2.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format_2bis.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format3.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format4.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format5.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format6.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format7.c \
	$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format8.c \
	$(PARSINGDIR)/$(CHECK_MAP)/check_maps.c \
	$(PARSINGDIR)/$(CHECK_MAP)/check_maps2.c \
	$(PARSINGDIR)/$(CHECK_MAP)/check_maps3.c \
	$(PARSINGDIR)/$(CHECK_MAP)/check_maps4.c \
	$(PARSINGDIR)/$(INIT_PARSING)/init_parsing.c \
	$(PARSINGDIR)/$(INIT_PARSING)/init_parsing2.c \
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



