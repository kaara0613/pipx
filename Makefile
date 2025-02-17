# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaara <kaara@student.42.jp>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 16:17:32 by kaara             #+#    #+#              #
#    Updated: 2025/01/17 16:17:32 by kaara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	main.c \
		allocation_pipex.c \
		allocation_and_cpy.c \
		store_args_in_struct.c \
		get_path_from_envp.c \
		spawn_child_and_process.c \
		setup_filefd.c \
		false_fork.c \
		chiled_process.c \
		validate_cmd_full_path.c \
		store_execve_argv.c \
		from_infile.c \
		setup_pipefd.c \
		to_outfile.c \
		free_execve_argv.c \
		free_exit.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
