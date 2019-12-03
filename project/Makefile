
# OUTPUT
NAME = gnl

# DIR
OUTDIR = ~/42/Games/outlib
OUTHDIR = ../../outlib/include
HDIR = .

# FICHIER
OUTLIB = outlib.a
SRC =	gnl.c \
		gnl_utils.c
	
# COMPILER
CC = gcc
WFLAG = -Wall -Wextra -Werror
DFLAG = -g3 -fsanitize=address

# AUTO
OUTHEAD = $(OUTDIR)/$(addsuffix .h, $(basename $(OUTLIB))
HEADER = $(HDIR)/$(addsuffix .h, $(NAME)))
INC = -I$(HDIR) -I$(OUTHDIR)
LIB = $(OUTDIR)/$(OUTLIB)


all : $(NAME)

$(NAME) :
	make -C $(OUTDIR)
	$(CC) -o $(NAME) $(INC) $(WFLAG) $(SRC) $(LIB) -DBUFFER_SIZE=1

test:
	make -C $(OUTDIR)
	$(CC) -o $(NAME) $(WFLAG) $(DFLAG) $(SRC) $(LIB) $(INC) -DBUFFER_SIZE=10
clean :
	make clean -C $(OUTDIR)

fclean :
	make fclean -C $(OUTDIR)
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
