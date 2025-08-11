paint.out: main.o setup.o commands.o write.o functions.o
	gcc -g -Wall -Werror -o paint.out main.o setup.o commands.o write.o functions.o

main.o: main.c setup.h commands.h
	gcc -g -Wall -Werror -c main.c

setup.o: setup.c setup.h
	gcc -g -Wall -Werror -c setup.c

commands.o: commands.c commands.h setup.h write.h functions.h
	gcc -g -Wall -Werror -c commands.c

write.o: write.c write.h commands.h setup.h
	gcc -g -Wall -Werror -c write.c

functions.o: functions.c functions.h commands.h setup.h
	gcc -g -Wall -Werror -c functions.c

clean:
	rm -fr *.o *.out