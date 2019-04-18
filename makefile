all: intl

intl: myfunc.o funcs.o myfunc.o
	gcc -Wall -Wl,--wrap,funcReplaced -Wl,--wrap,endFunc -o intl main.o funcs.o myfunc.o

myfunc.o: myfunc.c
	gcc -c myfunc.c

clean:
	rm -rf myfunc.o intl
