# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
LIBFT_DIR = libft
OBJ_DIR = obj

# New source files for server and client
SERVER_SRC = server.c
CLIENT_SRC = client.c
COMMON_SRC = utils_receive.c \
utils_send.c \
utils_bitmap.c \
utils_debug.c \

LIBFT_FILES = ft_isdigit.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strncpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strcmp.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_atol.c \
ft_calloc.c \
ft_strdup.c \
ft_strndup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putstr.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putnbr_fd_ulong.c \
ft_putnbr_fd_longlong.c \
ft_lutoa.c \
ft_llutoa.c \
ft_ullonglen.c \
ft_ulonglen.c \
ft_abs.c \
ft_intlen.c \
ft_putnbr_base.c \
ft_putuintnbr_base.c \
ft_putulonglongnbr_base.c \
ft_printf.c \
ft_printf_processors_one.c \
ft_printf_processors_two.c \
ft_printf_utils.c \
get_next_line.c \
get_next_line_utils.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstmap.c \
ft_min.c \
ft_max.c \


# Adding directory prefix to source files
SRC = $(addprefix $(SRC_DIR)/, $(SERVER_SRC) $(CLIENT_SRC) $(COMMON_SRC)) \
	  $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

# Object files for the original program, including common functionalities
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# Since SERVER_SRC and CLIENT_SRC are already included in SRC, we adjust SERVER_OBJ and CLIENT_OBJ
SERVER_OBJ = $(filter-out $(OBJ_DIR)/client.o, $(OBJ))
CLIENT_OBJ = $(filter-out $(OBJ_DIR)/server.o, $(OBJ))

# Executable names
SERVER_EXEC = server
CLIENT_EXEC = client

.PHONY: all clean fclean re

# Adjust the all rule to build both server and client
all: $(SERVER_EXEC) $(CLIENT_EXEC)

# Server and Client executable rules
$(SERVER_EXEC): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Generic rule for object files, now correctly handles all sources in SRC_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(SERVER_EXEC) $(CLIENT_EXEC)
	rm -rf $(OBJ_DIR)

re: fclean all