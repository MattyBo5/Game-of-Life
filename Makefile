CC = g++
CFLAGS = -Wall -g
OBJS = main.o world.o cell.o

Life: $(OBJS)
	$(CC) $(CFLAGS) -o Life $(OBJS)

main.o: main.cpp world.h
	$(CC) $(CFLAGS) -c main.cpp

world.o: world.cpp world.h cell.h
	$(CC) $(CFLAGS) -c world.cpp

cell.o: cell.cpp cell.h
	$(CC) $(CFLAGS) -c cell.cpp


