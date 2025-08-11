connectn.out: main.o validinput.o commandline.o setup.o game.o endgame.o
	gcc -g -Wall -Werror -o connectn.out main.o validinput.o commandline.o setup.o game.o endgame.o

main.o: main.c commandline.h setup.h game.h
	gcc -g -Wall -Werror -c main.c

validinput.o: validinput.c validinput.h
	gcc -g -Wall -Werror -c validinput.c

commandline.o: commandline.c commandline.h validinput.h
	gcc -g -Wall -Werror -c commandline.c

setup.o: setup.c setup.h
	gcc -g -Wall -Werror -c setup.c

game.o: game.c game.h validinput.h setup.h endgame.h
	gcc -g -Wall -Werror -c game.c

endgame.o: endgame.c endgame.h
	gcc -g -Wall -Werror -c endgame.c
	
clean:
	rm -fr *.o *.out
