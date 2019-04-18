myfunc.o: myfunc.c
	gcc -c myfunc.c

intl: myfunc.o, funcs.o, myfunc.o
	gcc -Wall -Wl,--wrap,funcReplaced -Wl,--wrap,endFunc -o intl main.o funcs.o myfunc.o

clean:
	rm myfunc.o intl
