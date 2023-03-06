# Colors
RED    	  	=  \033[0;91m
GRAY      	=  \033[0;37m
CYAN      	=  \033[0;96m
WHITE     	=  \033[0;97m
GREEN     	=  \033[0;92m
YELLOW          =  \033[0;93m
MAGENTA         =  \033[0;95m
DEF_COLOR       =  \033[0;39m# Colors
RED    	  	=  \033[0;91m
GRAY      	=  \033[0;37m
CYAN      	=  \033[0;96m
WHITE     	=  \033[0;97m
GREEN     	=  \033[0;92m
YELLOW          =  \033[0;93m
MAGENTA         =  \033[0;95m
DEF_COLOR       =  \033[0;39m

SHELL = /bin/bash
NAME = pipex.a
EXECUTABLE = pipex
CFLAGS = -Wall -Wextra -Werror -g

SRCS = \
	  create_child_process \
	  create_pipe \
	  execute_first_command \
	  handle_error \
	  init_args \
	  open_input_file \
	  pipex \
	  redirect_stdin_to_file_one \
	  redirect_stdout_to_pipe
LIBFT_SRCS = \
	  ft_strjoin \
	  ft_strdup \
	  ft_free_arr \
	  ft_strlcat \
	  ft_strlcpy \
	  ft_strlen

################ MANDATORY VARIABLES ################

LIBFT_PATH = libs/libft/
SRCS_PATH = srcs/srcs_mandatory/
OBJS_PATH = objs/
OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))

################# MANDATORY RULES #################

all: $(NAME)

make_libft:
	@make srcs_to_pipex -C $(LIBFT_PATH) --no-print-directory

$(NAME): make_libft $(OBJS) 
	@printf "\n$(YELLOW)Linking pipex Objects to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                       \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                        \r"; \
	fi; \
	done
	@printf "$(CYAN)Creating $(EXECUTABLE)$(DEF_COLOR)\n"; \
	$(CC) $(CFLAGS) $(NAME) $(LIBFT_PATH)srcs_to_pipex.a $(MLXFLAGS) -o $(EXECUTABLE);
	@printf "$(WHITE)Created Library $(RED)$(NAME)$(DEF_COLOR)                                             \n";
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)                  \n";

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@make LOOP --no-print-directory

LOOP: 
	@for file in $(SRCS); do \
		if [ $(SRCS_PATH)$$file.c -nt $(OBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[$(NAME)]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done

clean:
	@rm -rf $(OBJS_PATH)
	@make clean_pipex -C $(LIBFT_PATH) --no-print-directory
	@rm -f $(NAME)

fclean: clean
	@make fclean_pipex -C $(LIBFT_PATH) --no-print-directory
	@rm -f $(EXECUTABLE)

