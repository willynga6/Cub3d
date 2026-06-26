
NAME = cub3d
NAME_BONUS = cub3d_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-incompatible-pointer-types -g
CPPFLAGS = -Iincludes -Iget_next_line -Imlx
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lz

OBJ_DIR = obj

# ALL DIRECTORIES CONTAINING SOURCE FILES #

CLEANDIR = clean
PARSINGDIR = parsing
# PARING SUBDIRECTORIES #
CHECK_FILE_FORMAT = check_file_format
CHECK_MAP = check_map
INIT_PARSING = init_parsing
INIT_PLAYER = init_player
TOOLSDIR = tools
GNL = get_next_line
GAMEDIR = game
RAYCASTDIR = raycasting
BONUSDIR = bonus
MAIN = main.c
BONUS = bonus.c

SRCS = 	$(GAMEDIR)/window.c \
		$(GAMEDIR)/windows2.c \
		$(GAMEDIR)/raycasting.c \
		$(RAYCASTDIR)/raycast.c \
		$(RAYCASTDIR)/raycast1.c \
		$(RAYCASTDIR)/raycast2.c \
		$(RAYCASTDIR)/raycast3.c \
		$(RAYCASTDIR)/search_wall.c \
		$(GAMEDIR)/door_check.c \
		$(GAMEDIR)/texture.c \
		$(GAMEDIR)/texture2.c \
		$(GAMEDIR)/mm_map.c \
		$(GAMEDIR)/key_push.c \
		$(GAMEDIR)/rotation.c \
		$(GAMEDIR)/game_loop.c \
		$(GAMEDIR)/game_loop2.c \
		$(TOOLSDIR)/tools1.c \
		$(TOOLSDIR)/tools2.c \
		$(TOOLSDIR)/tools3.c \
		$(PARSINGDIR)/parsing.c \
		$(PARSINGDIR)/check_extension.c \
		$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_format.c \
		$(PARSINGDIR)/$(CHECK_FILE_FORMAT)/check_file_formatbis.c \
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
		$(PARSINGDIR)/$(INIT_PLAYER)/init_player.c \
		$(PARSINGDIR)/$(INIT_PLAYER)/init_player2.c \
		$(GNL)/get_next_line.c \
		$(GNL)/get_next_line_utils.c \
		$(CLEANDIR)/malloc.c \
		$(BONUSDIR)/gun_texture.c \
		$(BONUSDIR)/gun_texture2.c \
		$(BONUSDIR)/gun.c \
		$(BONUSDIR)/mouss_event.c \
		$(BONUSDIR)/parsing_bonus.c \
		$(BONUSDIR)/game_loop_bonus.c \
		$(BONUSDIR)/render_frame_bonus.c 


OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
MAIN_OBJ = $(MAIN:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS:%.c=$(OBJ_DIR)/%.o)


RM = rm -rf

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME) $(MLX_FLAGS)

bonus: $(OBJS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) -o $(NAME_BONUS) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all


