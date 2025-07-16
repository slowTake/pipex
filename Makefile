# --- Project Specifics ---
NAME = pipex
# Pipex source files
SRCS = src/pipex.c \
        src/utility_cmd.c \
        src/utility_fts.c

# Object directory for all object files (pipex and libft)
OBJ_DIR = .objs

# Pipex object files (will be placed in OBJ_DIR)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Include paths for pipex sources
INCLUDES = -I./includes

# --- LIBFT Specifics ---
LIBFT_PATH = libft
LIBFT_SRCS = $(addprefix $(LIBFT_PATH)/, \
        ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memset.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_bzero.c \
)

LIBFT_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(LIBFT_SRCS:.c=.o)))

LIBFT_INC = -I$(LIBFT_PATH)

# --- Compiler & Flags ---
COMPILER = cc
COMPILERFLAGS = -Wall -Wextra -Werror -g

# --- Rules ---

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(COMPILER) $^ -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(COMPILER) $(COMPILERFLAGS) $(INCLUDES) $(LIBFT_INC) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_PATH)/%.c | $(OBJ_DIR)
	$(COMPILER) $(COMPILERFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	# Remove all generated object files (both pipex and libft)
	@rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	# Remove the object directory and the executable
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
