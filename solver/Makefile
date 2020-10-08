##
## EPITECH PROJECT, 2019
## makefile
## File description:
## dante
##

NAME	=	solver

CC	=	gcc

CFLAGS	+=	-I ../icl/ -g3

FILES	=	../lib/my_putchar.c	\
		../lib/my_putstr.c	\
		src/main.c	\
		src/maze_to_array.c	\
		src/solver.c

OBJ	=	$(FILES:.c=.o)

RED             =       \033[0;31m
GREEN           =       \033[0;32m
GREY            =       \033[90m
BLUE            =       \033[0;94m
NC              =       \033[0m
IRED            =       \033[0;91m
PURPLE          =       \033[0;95m

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e '${BLUE}Cflags${NC}: ${GREY}$(CFLAGS) ${NC}'
	@$(CC) $(OBJ) -o $(NAME) 2>>errors.txt\
	&& echo -e '${BLUE}Create${NC}: ${GREY}./$(NAME)${NC}'\
	|| echo -e '${RED}[ FAILED ]${NC}: __Create__${GREY} ./$(NAME)${NC}'

%.o :		%.c
	@-$(CC) -o $@ -c $< $(CFLAGS) 2>>errors.txt\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'\
		&& echo -ne '${PURPLE}' && grep  $< errors.txt |\
		grep warning |cut -d':' -f2- |cut -d'[' -f-1\
		&& echo -ne '${IRED}' && grep  $< errors.txt |\
		grep error |cut -d':' -f2-\
		||:

clean:
	@rm -rf $(OBJ)
	@rm -rf vgcore.*
	@rm -rf errors.txt 2>/dev/null
	@echo -e '${BLUE}Clean${NC} : ${GREY}OK'

fclean:	clean
	@rm -rf $(NAME)
	@echo -e '${BLUE}Fclean${NC}: ${GREY}$(NAME) removed'

re:	fclean all
