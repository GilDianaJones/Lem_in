SRC=$(addsuffix .c, main parse_1 parse_2 parse_3 parse_4 error paths_1 paths_2 \
	paths_3 paths_4 paths_5 algo_1 algo_2 erase)
OBJ=$(addprefix obj/,$(SRC:.c=.o))
NAME=lem-in
LIBFT=libft/libft.a
WFLAGS= -Werror -Wall -Wextra

.PHONY: clean fclean re all lib dobj

all: lib dobj $(NAME)

lib:
	make -C libft

dobj:
	mkdir -p obj

$(NAME): $(LIBFT) $(OBJ)
	gcc $(OBJ) -o $@ -L./libft -lft $(WFLAGS)

obj/%.o: src/%.c
	gcc -o $@ -c $< -I./includes $(WFLAGS)

clean:
	rm -rf obj
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
