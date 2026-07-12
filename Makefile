FILES = main.c files/configure.c utils/utils.c main/parse.c index.c

comp: 
	g++ $(FILES) -o todo

expd:
	g++ -E $(FILES) -o expanded.i

sep:
	g++ -c main.c
	g++ -c files/configure.c
	g++ -c utils/utils.c
	g++ -c main/parse.c 
	g++ -c index.c

all:
	g++ $(FILES) -o todo
	./todo help