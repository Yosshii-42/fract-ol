NAME	=	fractol
CFLAGS	=	-Wall -Wextra -Werror -O3 -MMD -MP
SRCS	=	src/main.c \
			src/mathematics_part.c \
			src/open_and_close.c \
			src/handler.c \
			src/data_set.c
OBJS	=	$(SRCS:.c=.o)
FRAC_INC = fractol.h
MINILIBX_DIR := ./minilibx_opengl
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR)
LIBS	=	-lm -lmlx
LIBFT	= ./libft/libft.a

.PHONY: all
all: $(NAME)

-include $(OBJS:.o=.d)

$(NAME): $(OBJS) $(MINILIBX) $(FRAC_INC)
	make -C ./libft
	make -C minilibx_opengl
	$(CC) $(OBJS) $(LIBFT) $(LDFLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MINILIBX):
	$(MAKE) -j4 -C $(MINILIBX_DIR)

bonus: all

clean:
	make fclean -C ./libft
	make fclean -C ./minilibx_opengl
	rm -f $(OBJS)
	rm -f src/*.d

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean

.PHONY: re clean fclean bonus
re: fclean all
