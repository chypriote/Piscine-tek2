NAME=	MyGKrellM

SRC=	main.cpp		\
	misc.cpp		\
	Monitor.cpp		\
	Modules/DateHour.cpp	\
	Modules/OSKernel.cpp	\
	Modules/UserInfo.cpp	\
	Modules/RAMInfo.cpp	\
	Modules/CPUInfo.cpp	\
	Modules/Network.cpp	\
	Display/ADisplay.cpp	\
	Display/curses.cpp	\
	Display/DateHourDisplay.cpp	\
	Display/OSKernelDisplay.cpp	\
	Display/UserInfoDisplay.cpp	\
	Display/RAMInfoDisplay.cpp	\
	Display/CPUInfoDisplay.cpp	\
	Display/NetworkDisplay.cpp	\


CC=	g++ -Wall -Wextra -W

RM=	rm -f

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) -lncurses

fclean:
	$(RM) $(NAME)

re:	fclean all
