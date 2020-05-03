##
## EPITECH PROJECT, 2020
## Makefile header
## File description:
## Main makefile
##

CC				=			gcc -g		# on garde le -g pour valgrind

NAME			=			my_rpg

SRC				=			src/main.c							\
							src/events.c						\
							src/draw.c							\
							src/init/init_game.c				\
							src/init/init_game_2.c				\
							src/destroy.c						\
							src/transition.c					\
							src/my_rpg.c						\
							src/dialogues.c						\
							src/init/init_perso.c				\
							src/combat/combat_scene.c			\
							src/combat/combat_events.c			\
							src/combat/intro_combat.c			\
							src/gameplay.c						\
							src/anim/set_rect_pos.c				\
							src/anim/moves_perso.c				\
							src/anim/move_up.c					\
							src/anim/move_down.c				\
							src/anim/move_left.c				\
							src/anim/move_right.c				\
							src/anim/move_events.c				\
							src/anim/atk_anim.c					\
							src/init/init_enemy.c				\
							src/update_buttons_spr.c			\
							src/deal_dmg.c						\
							src/init/init_map.c					\
							src/inventory.c						\
							src/my_str_to_word_array_space.c	\
							src/nbr_str.c						\
							src/my_nbrlen.c						\
							src/game_over.c						\
							src/position_of_mouse.c				\
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