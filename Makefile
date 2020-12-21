# Name

NAME = libgnl.a

# File

SRC_NAME= get_next_line \
		  get_next_line_utils

HDR_NAME= get_next_line
TEST_NAME = test

ifdef BONUS
SRC = $(addsuffix .c, $(addsuffix _bonus, $(SRC_NAME)))
HDR = $(addprefix $(addprefix $(HDR_NAME), _bonus), .h)
FLAGS = $(addprefix $(FLAG),    -DBONUS=1)
else
SRC = $(addsuffix .c, $(SRC_NAME))
HDR = $(addprefix $(HDR_NAME), .h)
endif

MAIN = main.c

# Compiler

CC = clang
F_WRN = -Wall -Werror -Wall
F_DEF = -DBUFFER_SIZE=32 
FLAG = $(F_WRN) $(F_DEF)


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) : $(SRC) $(HDR)
	$(CC) $(FLAG) -c $(SRC)

$(TEST_NAME) : $(NAME) $(MAIN)
	$(CC) $(FLAGS) -o $(TEST_NAME) $(MAIN) $(NAME)

bonus :
	make BONUS=1 all

test_bonus :
	make BONUS=1 $(TEST_NAME)

clean :
	rm -rf $(OBJ) $(addsuffix .o, $(addsuffix _bonus, $(basename $(OBJ))))

fclean : clean
	rm -rf $(NAME)
	rm -rf $(TEST_NAME)

re : fclean all

re_bonus : fclean
	make BONUS=1 all

.PHONY: all clean fclean re bonus test_bonus
