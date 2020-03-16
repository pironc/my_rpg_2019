##
## EPITECH PROJECT, 2019
## Makefile header
## File description:
## makefile
##

SRC 	=		my_put_nbr.c					\
				my_putchar.c					\
				my_putstr.c

OBJ 	=		$(SRC:%.c=%.o)

NAME 	=		libmy.a

LIB		=	-I include/

CFLAGS	=	$(LIB)

all:	$(NAME)

$(NAME):		$(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f *.o
		rm -f ../../src/*.o

re:		fclean all