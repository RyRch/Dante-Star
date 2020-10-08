##
## EPITECH PROJECT, 2019
## makefile
## File description:
## dante
##

GREY            =       \033[90m
BLUE            =       \033[0;94m
NC              =       \033[0m
GEN		=	./generator
SOL		=	./solver

all:
	@echo -e '$(BLUE)Create${NC} : $(GREY)binary'
	@make -s -C $(GEN)
	@make -s -C $(SOL)

clean:
	@make clean -s -C $(GEN)
	@make clean -s -C $(SOL)
	@echo -e '${BLUE}Clean${NC} : ${GREY}OK'

fclean:	clean
	@make fclean -s -C $(GEN)
	@make fclean -s -C $(SOL)
	@echo -e '${BLUE}Fclean${NC} : ${GREY} binary removed'

re:	fclean all
