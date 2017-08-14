areas: areas.o geometry.o
	gcc -o areas areas.o geometry.o

areas.o: areas.c geometry.h
	gcc -c areas.c

geometry.o: geometry.c geometry.h
	gcc -c geometry.c
