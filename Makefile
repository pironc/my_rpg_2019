##
## EPITECH PROJECT, 2020
## Makefile header
## File description:
## Main makefile
##

CC				=			gcc -g		# on garde le -g pour valgrind

NAME			=			my_rpg

SRC				=			src/main.c											\
							src/anim/atk_anim.c									\
							src/anim/move_down.c								\
							src/anim/move_events.c								\
							src/anim/move_left.c								\
							src/anim/move_right.c								\
							src/anim/move_up.c									\
							src/anim/moves_perso.c								\
							src/anim/set_rect_pos.c								\
							src/basic_functions/my_nbrlen.c						\
							src/basic_functions/my_str_to_word_array_space.c	\
							src/basic_functions/nbr_str.c						\
							src/combat/combat_events.c							\
							src/combat/combat_scene.c							\
							src/combat/deal_dmg.c								\
							src/combat/intro_combat.c							\
							src/destroy/destroy.c								\
							src/draw/draw.c										\
							src/events/analyse_events.c							\
							src/events/dialogues.c								\
							src/events/events_menu.c							\
							src/events/events.c									\
							src/events/game_over.c								\
							src/events/position_of_mouse.c						\
							src/events/transition.c								\
							src/gameplay/gameplay.c								\
							src/gameplay/inventory.c							\
							src/gameplay/my_rpg.c								\
							src/init/button.c									\
							src/init/init_enemy.c								\
							src/init/init_game_2.c								\
							src/init/init_game.c								\
							src/init/init_house.c								\
							src/init/init_map.c									\
							src/init/init_perso.c								\
							src/init/init_scenes.c								\
							src/init/init_stats.c								\
							src/init/update_buttons_spr.c						\

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