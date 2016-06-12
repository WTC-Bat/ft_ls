
NAME = ft_ls
SRC = "./src/"
HEAD = "./includes/"
HEADLFT = "./libft/"
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	cd libft && $(MAKE) && $(MAKE) clean
	mv libft/libft.a ./
	gcc $(FLAGS) -I$(HEAD) -I$(HEADLFT) $(SRC)ft_ls.c libft.a -o ft_ls

clean:
	rm -f libft.a

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all
