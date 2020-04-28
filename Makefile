##
## EPITECH PROJECT, 2020
## Makefile header
## File description:
## Main makefile
##

CC				=			gcc -g		# on garde le -g pour valgrind

NAME			=			my_rpg

SRC				=			src/main.c				\
							src/events.c			\
							src/draw.c				\
							src/init_game.c			\
							src/destroy.c			\
							src/transition.c		\
							src/my_rpg.c			\
							src/init_perso.c		\
							src/enemy.c				\
							src/combat_scene.c		\
							src/gameplay.c			\
							src/set_rect_pos.c		\
							src/moves_perso.c		\
							src/move_events.c		\
							#src/pause_menu.c

OBJ				=			$(SRC:%.c=%.o)

LIB				=			-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS			=			-I include/ $(LIB) -L lib/ -lmy

all:					$(NAME)
$(NAME):				$(OBJ)
						$(MAKE) -C lib/
						$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean:
						$(MAKE) -C lib/ clean
						$(RM) -rf $(OBJ)
fclean:					clean
						$(MAKE) -C lib/ fclean
						$(RM) -rf $(NAME)
re:						fclean all