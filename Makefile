NAME = 21SH

SRCS =	srcs/get_line.c srcs/main.c srcs/ft_run_s.c srcs/ft_s_args.c \
        srcs/ft_history.c srcs/ft_run_args.c srcs/ft_cd.c 

INCLUDE = -I includes/

FLAGS = -Wall -Werror -Wextra

LFLAG = -L./libft/ -lft

all:
	@make -C libft/
	@gcc $(FLAGS) $(SRCS) $(INCLUDE) $(LFLAGS)
	@mv a.out $(NAME)

clean:
	@rm $(NAME)

re: clean all

