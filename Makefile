# --- Project Specifics ---
NAME = pipex
SRCS = src/pipex.c \
		src/utility_cmd.c 
		
INCLUDES = -I./includes

OBJ_DIR = .objs

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

INCLUDES = -I./includes

# --- LIBFT Specifics ---

LIBFT_PATH = libft
LIBFT_A = $(LIBFT_PATH)/libft.a
LIBFT_INC = -I$(LIBFT_PATH)/includes

# --- Compiler & Flags ---
COMPILER = cc
COMPILERFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(LIBFT_PATH) -lft

# --- Rules ---

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_A):
	@make -C $(LIBTFT_PATH)

$(NAME): $(LIBFT_A) $(OBJS)

	$(COMPILER) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(COMPILER) $(COMPILERFLAGS) $(INCLUDES) $(LIBFT_INC) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re