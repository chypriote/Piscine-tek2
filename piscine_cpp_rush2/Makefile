NAME=	atelier

SRC=	main-factory.cpp		\
	Object/Object.cpp	\
	Usine/Table.cpp		\
	Usine/ConveyorBelt.cpp	\
	Object/Toy.cpp		\
	Object/Teddy.cpp	\
	Object/LittlePony.cpp	\
	Object/Wrap.cpp		\
	Object/Box.cpp		\
	Object/GiftPaper.cpp	\
	Elf/ElfOfPePeNoel.cpp	\

CC=	clang++ -Wall -Wextra -W

RM=	rm -rf

all:	ascii $(NAME)

ascii: 
	@cat elf

$(NAME):
	@$(CC) -o $(NAME) $(SRC)

clean:
	@$(RM) $(NAME)

re:	clean all

# echo'                ___,@' \
# echo'               /  <'\
# echo'          ,_  /    \  _,'\
# echo'      ?    \`/______\`/'\
# echo'   ,_(_).  |; (e  e) ;|'\
# echo'    \___ \ \/\   7  /\/    _\8/_'\
# echo'        \/\   \'==\'/      | /| /|'\
# echo'         \ \___)--(_______|//|//|'\
# echo'          \___  ()  _____/|/_|/_|'\
# echo'             /  ()  \    `----\''\
# echo'            /   ()   \\'\
# echo'           \'-.______.-\''\
# echo'         _    |_||_|    _'\
# echo'        (@____) || (____@)'\
# echo'         \______||______/'\
