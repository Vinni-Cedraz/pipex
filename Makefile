NAME = pipex
CFLAGS = -Wall -Wextra -Werror -g
SRC_NAMES = \
	  create_child_process.c \
	  create_pipe.c \
	  execute_first_command.c \
	  ft_split.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  handle_error.c \
	  init_args.c \
	  open_input_file.c \
	  pipex.c \
	  redirect_stdin_to_file_one.c \
	  redirect_stdout_to_pipe.c \
	  ft_free_arr.c \
	  ft_strdup.c

SRC_PATH = src/

## concatenates SRC_PATH with SRC
SRC = $(addprefix $(SRC_PATH), $(SRC_NAMES))


all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f *.o

fclean:
	@rm -f $(NAME)

