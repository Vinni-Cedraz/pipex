# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:11:55 by vcedraz-          #+#    #+#              #
#    Updated: 2023/03/12 16:35:23 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## SET-UP VARIABLES ##
SHELL := /bin/bash
NAME = libft.a
NAME_BONUS = libft_bonus.a
NAME_PIPEX = srcs_to_pipex.a
NAME_PIPEX_BONUS = srcs_to_pipex_bonus.a
CFLAGS = -Wall -Werror -Wextra -g
AR = ar -rs
RM = rm -f
OBJS_PATH = ./objs/
OBJSB_PATH = ./objs_bonus/
PRNTF_OBJS_PATH = ./objs_printf/
PIPEX_OBJS_PATH = ./objs_pipex/
PIPEX_OBJSB_PATH = ./objs_pipex_bonus/
DEF_COLOR = \033[0;39m
GRAY = \033[0;37m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

## SRCS VARIABLES ##
SRCS = ft_abs \
ft_islow \
ft_atoi \
ft_free_t_split \
ft_free_arr \
ft_free_arr_size \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_ishexlow \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memorylen \
ft_memset \
ft_numlen \
ft_putchar \
ft_putchar_fd \
ft_strlen \
ft_atoi_base \
ft_strncmp \
ft_word_counter \
ft_calloc \
ft_memmove \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_striteri \
ft_strrchr \
ft_strrev \
ft_swap \
ft_tolower \
ft_toupper \
ft_bzero \
ft_isalnum \
ft_putendl_fd \
ft_strchr \
ft_strdup \
ft_strlcat \
ft_strlcpy \
ft_strmapi \
ft_strnstr \
ft_strjoin \
ft_strtrim \
ft_substr \
ft_gnl \
ft_itoa \
ft_split \

BSRCS = ft_lstadd_back \
ft_lstadd_front \
ft_lstfree \
ft_lstlast \
ft_lstnew \
ft_lstsize \
ft_lstprint \
ft_lstadd_here \
ft_lstdel_here \
ft_lstgetby_index \
ft_lstgetby_content \
ft_lst_make_it_circular \
ft_lstcircular_free \
ft_lstpop \
ft_lstshift \
	

PIPEX_SRCS = \
		   ft_memchr \
		   ft_word_counter \
		   ft_split \
		   ft_split_envp \
		   ft_strjoin \
		   ft_free_arr \
		   ft_strdup \
		   ft_calloc \
		   ft_free_t_split \
		   ft_strlcat \
		   ft_strlcpy \
	  	   ft_putendl_fd \
		   ft_strrchr \
		   ft_strncmp


## OBJS VARIABLES ##

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
OBJSB = $(patsubst %, $(OBJSB_PATH)%.o, $(BSRCS))
OBJS_PRNTF = $(patsubst %, $(PRNTF_OBJS_PATH)%.o, $(PRNTF_SRCS))
OBJS_PIPEX = $(patsubst %, $(PIPEX_OBJS_PATH)%.o, $(PIPEX_SRCS))
OBJSB_PIPEX = $(patsubst %, $(PIPEX_OBJSB_PATH)%.o, $(PIPEX_SRCS_BONUS))
MOD_OBJ = $(shell find . -path "./objs/*.o" -type f -newer $(NAME))
MOD_OBJB = $(shell find . -path "./objs_bonus/*.o" -type f -newer $(NAME_BONUS))
MOD_OBJ_PRNTF = $(shell find . -path "./objs_printf/*.o" -type f -newer $(NAME_PRNTF))
MOD_OBJ_PIPEX = $(shell find . -path "./objs_pipex/*.o" -type f -newer $(NAME_PIPEX))
MOD_OBJB_PIPEX = $(shell find . -path "./objs_pipex_bonus/*.o" -type f -newer $(NAME_PIPEX_BONUS))

## COMPILATION RULES ##

all : $(NAME) 

srcs_to_printf : $(NAME_PRNTF)

srcs_to_pipex_bonus: $(NAME_PIPEX_BONUS)

srcs_to_pipex : $(NAME_PIPEX)

bonus : $(NAME_BONUS)

all_all: all srcs_to_printf srcs_to_pipex bonus

$(NAME) : $(OBJS) 
	@printf "\n$(YELLOW)Linking Mandatory Objects to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                                         \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                                                        \r"; \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME)$(DEF_COLOR)                                                                              \n"; \

$(NAME_PIPEX) : $(OBJS_PIPEX) 
	@printf "\n$(YELLOW)Linking pipex Objects From libft to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ_PIPEX); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_PIPEX)$(DEF_COLOR)                                                           \r"; \
		ar -rsc $(NAME_PIPEX) $$file; \
	done
	@for file in $(PIPEX_SRCS); do \
	if [[ -z "$$(nm $(NAME_PIPEX) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME_PIPEX)$(DEF_COLOR)                                                          \r"; \
		ar -rsc $(NAME_PIPEX) $(PIPEX_OBJS_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_PIPEX)$(DEF_COLOR)                                                                              \n"; \

$(NAME_PIPEX_BONUS) : $(OBJSB_PIPEX)
	@printf "\n$(YELLOW)Linking pipex Bonus Objects From libft to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJB_PIPEX); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_PIPEX_BONUS)$(DEF_COLOR)                                                        \r"; \
		ar -rsc $(NAME_PIPEX_BONUS) $$file; \
	done
	@for file in $(PIPEX_SRCS_BONUS); do \
	if [[ -z "$$(nm $(NAME_PIPEX_BONUS) | grep $${file}.o:)" ]]; then \
		printf "$(CYAN)Linking $(WHITE)$$file.o $(GRAY)to $(RED)$(NAME_PIPEX_BONUS)$(DEF_COLOR)                                                      \r"; \
		ar -rsc $(NAME_PIPEX_BONUS) $(PIPEX_OBJSB_PATH)$$file.o; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_PIPEX_BONUS)$(DEF_COLOR)                                                                                \n"; \

$(NAME_BONUS) : $(NAME) $(OBJSB) 
	@printf "\n$(YELLOW)Creating $(NAME_BONUS) Library With ALL Objects from libft...$(DEF_COLOR)\n";
	@if	[[ -z "$$(nm $(NAME_BONUS) | grep ft_lstnew.o:)" ]]; then \
		cp $(NAME) $(NAME_BONUS); \
	fi
	@for file in $(MOD_OBJB); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                             \r"; \
		ar -rsc $(NAME_BONUS) $$file; \
	done
	@for file in $(BSRCS); do \
	if [[ -z "$$(nm $(NAME_BONUS) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME_BONUS) $(OBJSB_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                              \r"; \
		printf "ar -rsc $(NAME_BONUS) $(OBJSB_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file $(GREEN)OK$(DEF_COLOR)\n"; \
	fi; \
	done
	@printf "$(WHITE)Created Library $(RED)$(NAME_BONUS)$(DEF_COLOR)                                                                                \n"; \

$(OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling All libft Sources...$(DEF_COLOR)\n\n"
	@make LIBFT_LOOP --no-print-directory

$(OBJSB_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Bonus libft Sources...$(DEF_COLOR)\n\n"
	@make BONUS_LIBFT_LOOP --no-print-directory

$(PRNTF_OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Libft Sources to Printf... $(DEF_COLOR)\n\n"
	@make PRNTF_LOOP --no-print-directory

$(PIPEX_OBJS_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling libft Sources... $(DEF_COLOR)\n\n"
	@make PIPEX_LOOP --no-print-directory

$(PIPEX_OBJSB_PATH)%.o : %.c
	@printf "\n$(YELLOW)Compiling Bonus libft Sources... $(DEF_COLOR)\n\n"
	@make PIPEX_BONUS_LOOP --no-print-directory

PIPEX_LOOP :
	@mkdir -p $(PIPEX_OBJS_PATH)
	@for file in $(PIPEX_SRCS); do \
	if [ $$file.c -nt $(PIPEX_OBJS_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file.c...$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(PIPEX_OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(PIPEX_OBJS_PATH)$$file.o$(DEF_COLOR)\n"; \
		printf "$(WHITE)$$file.c $(GREEN)OK$(DEF_COLOR)\n\n"; \
	fi; \
	done

PIPEX_BONUS_LOOP :
	@mkdir -p $(PIPEX_OBJSB_PATH)
	@for file in $(PIPEX_SRCS_BONUS); do \
	if [ $$file.c -nt $(PIPEX_OBJSB_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file.c...$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(PIPEX_OBJSB_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(PIPEX_OBJSB_PATH)$$file.o$(DEF_COLOR)\n"; \
		printf "$(WHITE)$$file.c $(GREEN)OK$(DEF_COLOR)\n\n"; \
	fi; \
	done

PRNTF_LOOP :
	@mkdir -p $(PRNTF_OBJS_PATH)
	@for file in $(PRNTF_SRCS); do \
		if [ $$file.c -nt $(PRNTF_OBJS_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(PRNTF_OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(PRNTF_OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(PRNTF_OBJS_PATH)$(DEF_COLOR)\n" \

LIBFT_LOOP :
	@mkdir -p $(OBJS_PATH)
	@for file in $(SRCS); do \
		if [ $$file.c -nt $(OBJS_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(OBJS_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(OBJS_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(OBJS_PATH)$(DEF_COLOR)\n" \

BONUS_LIBFT_LOOP :
	@mkdir -p $(OBJSB_PATH)
	@for file in $(BSRCS); do \
		if [ $$file.c -nt $(OBJSB_PATH)$$file.o ]; then \
		printf "$(GREEN)[libft] $(CYAN)Compiling $(WHITE)$$file$(DEF_COLOR)\n"; \
		$(CC) $(CFLAGS) -c $$file.c -o $(OBJSB_PATH)$$file.o; \
		printf "$(CC) $(CFLAGS) -c $$file.c -o $(OBJSB_PATH)$$file.o\n"; \
		printf "$(WHITE)$$file$(GREEN) OK\n\n$(DEF_COLOR)"; \
		fi; \
	done
	@printf "$(GREEN)Objects Compiled Into $(WHITE)$(OBJSB_PATH)$(DEF_COLOR)\n" \

## CLEANING RULES ##
clean_all :
	@make clean --no-print-directory
	@make clean_bonus --no-print-directory
	@make clean_pipex --no-print-directory
	@make clean_printf --no-print-directory
	
clean:
	@if [ -d $(OBJS_PATH) ]; then \
		rm -rf $(OBJS_PATH); \
		printf "$(RED)Libft Objects Removed$(DEF_COLOR)\n"; \
	fi
	@if [ -d $(OBJSB_PATH) ]; then \
		rm -rf $(OBJSB_PATH); \
		printf "$(RED)Libft Bonus Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out
	@rm -f st*

clean_libft:
	@if [ -d $(OBJS_PATH) ]; then \
		rm -rf $(OBJS_PATH); \
		printf "$(RED)Libft Objects Removed$(DEF_COLOR)\n"; \
	fi

clean_printf:
	@if [ -d $(PRNTF_OBJS_PATH) ]; then \
		rm -rf $(PRNTF_OBJS_PATH); \
		printf "$(RED)Printf Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_pipex:
	@if [ -d $(PIPEX_OBJS_PATH) ]; then \
		rm -rf $(PIPEX_OBJS_PATH); \
		printf "$(RED)PIPEX Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_pipex_bonus:
	@if [ -d $(PIPEX_OBJSB_PATH) ]; then \
		rm -rf $(PIPEX_OBJSB_PATH); \
		printf "$(RED)PIPEX Bonus Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

clean_bonus :
	@if [ -d $(OBJSB_PATH) ]; then \
		rm -rf $(OBJSB_PATH); \
		printf "$(RED)Bonus Libft Objects Removed$(DEF_COLOR)\n"; \
	fi
	@rm -f a.out

fclean_all : fclean_printf fclean_pipex fclean_bonus fclean

fclean :
	@make clean --no-print-directory;
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "$(RED)$(NAME) Removed$(DEF_COLOR)\n"; \
	fi
	@make fclean_bonus --no-print-directory

fclean_libft :
	@make clean_libft --no-print-directory;
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		printf "$(RED)$(NAME) Removed$(DEF_COLOR)\n"; \
	fi

fclean_printf :
	@make clean_printf --no-print-directory;
	@if [ -f $(NAME_PRNTF) ]; then \
		rm -f $(NAME_PRNTF); \
		printf "$(RED)$(NAME_PRNTF) Removed$(DEF_COLOR)\n"; \
	fi

fclean_pipex :
	@make clean_pipex --no-print-directory;
	@if [ -f $(NAME_PIPEX) ]; then \
		rm -f $(NAME_PIPEX); \
		printf "$(RED)$(NAME_PIPEX) Removed$(DEF_COLOR)\n"; \
	fi

fclean_pipex_bonus :
	@make clean_pipex_bonus --no-print-directory;
	@if [ -f $(NAME_PIPEX_BONUS) ]; then \
		rm -f $(NAME_PIPEX_BONUS); \
		printf "$(RED)$(NAME_PIPEX_BONUS) Removed$(DEF_COLOR)\n"; \
	fi

fclean_bonus :
	@make clean_bonus --no-print-directory;
	@if [ -f $(NAME_BONUS) ]; then \
		rm -f $(NAME_BONUS); \
		printf "$(RED)$(NAME_BONUS) Removed$(DEF_COLOR)\n"; \
	fi

re : fclean all

re_printf : fclean_printf srcs_to_printf

re_pipex : fclean_pipex srcs_to_pipex

re_bonus : fclean_bonus srcs_to_bonus

phony : all clean fclean re bonus printf
