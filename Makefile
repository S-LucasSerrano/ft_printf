NAME = libftprintf.a

SRC = ft_printf.c \
	flags.c \
	print_chars.c print_dec.c print_hex.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra

ALL_OBJ = *.o
LIBS_PATH = libft/
LIBS = $(addprefix $(LIBS_PATH), $(ALL_OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     ...genereting .a"
	@ar rc $(NAME) $(OBJ) $(LIBS)
	@echo "- generated"

$(OBJ): $(SRC)
	@echo "     ...turning .c into .o"
	@make -C $(LIBS_PATH)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@echo "     ...cleaning"
	@make -C $(LIBS_PATH) clean
	@rm -f $(OBJ)

fclean: clean
	@echo "     ...f cleaning"
	@rm -f $(NAME)
	@make -C $(LIBS_PATH) fclean

re: fclean all
