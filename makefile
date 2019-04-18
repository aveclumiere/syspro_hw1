myfunc: myfunc.c
	gcc -c myfunc.c

intl: myfunc.o, funcs.o, myfunc.o
	make myfunc
	gcc -Wall -Wl,--wrap,funcReplaced -Wl,--wrap,endFunc -o intl main.o funcs.o myfunc.o

clean:
	rm myfunc.o intl
