NAME =		fdf
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror 
RM =		rm -f
LIBFT =		-L./42lib -lft
SRCS =		srcs/main.c \
			srcs/fdf_file_main_checker.c\
			srcs/fdf_main_file_parser.c \
			srcs/fdf_get_map_height_width.c \
			srcs/fdf_extract_map_data_from_fd.c \
			srcs/fdf_error.c \
			srcs/fdf_key_event.c\
			srcs/fdf_parse_utils.c \
			srcs/fdf_bresenham.c \
			srcs/fdf_projection_on_screen.c 

OBJS =		$(SRCS:.c=.o)

all: $(NAME)

MAC_L =		-L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
LINUX_L =	-L./minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(OBJS)
	make -C 42lib
ifeq ($(shell uname), Linux)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINUX_L) -o $(NAME)
else
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MAC_L) -o $(NAME)
endif

clean:
	@make clean -C 42lib
ifeq ($(shell uname), Linux)
	@make clean -C minilibx-linux
else
	@make clean -C minilibx_macos 
endif
	$(RM) $(OBJS)

fclean: clean
ifeq ($(shell uname), Linux)
	rm -f minilibx-linux/libmlx_Linux.a
else
	rm -f minilibx_macos/libmlx.a
endif
	rm -f 42lib/libft.a
	$(RM) $(NAME)

re: fclean all


test: $(OBJS)
	@make -C 42lib
ifeq ($(shell uname), Linux)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) -g3 $(OBJS) $(LIBFT) $(LINUX_L) -o $(NAME)
else
	@make -C minilibx_macos
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(MAC_L) -o $(NAME)
endif
	./fdf test_maps/42.fdf

.PHONY: all clean fclean re libft test
