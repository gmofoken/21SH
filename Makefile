NAME = 21sh

SRCS =	srcs/main.c srcs/get_line.c srcs/ft_run_s.c srcs/ft_s_args.c \
	srcs/ft_history.c srcs/ft_run_args.c srcs/ft_cd.c srcs/ft_set_env.c \
	srcs/ft_do_e.c srcs/ft_echo.c srcs/ft_echo_quo.c srcs/ft_putecho.c \
	srcs/ft_unsetenv.c srcs/ft_sub_s.c

HEADER = -I includes

LFLAGS = -L libft/ -lft

FLAGS = -o 21sh -Wall -Werror -Wextra

all:
	@make -C libft/
	@gcc $(FLAGS) $(SRCS) $(HEADER) $(LFLAGS)

clean:
	@rm $(NAME)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re: fclean all
