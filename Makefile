# --- Project Specifics ---
NAME = pipex.a
SRCS = pipex.c\
		utility_cmd.c\
		utility_fts.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./includes

# --- LIBFT Specifics ---

LIBFT_PATH = LIBFT
LIBFT_A = $(LIBFT_PATH)/libft.a
LIBFT_INC = -I$(LIBFT_PATH)/includes

# --- Compiler & Flags ---
COMPILER = cc
COMPILERFLAGS = -Wall -Wextra -Werror
LDFLAGS == -L$

# --- Rules ---

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
		ar rcs $@ $^

%.o: %.c
		$(COMPILER) $(COMPILERFLAGS) -I. -c $< -o $@

clean: 
		@make -C $(LIBFT_PATH) clean
		@rm -f $(OBJS)

fclean: clean
		@make -C $(LIBFT_PATH) fclean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT_A)