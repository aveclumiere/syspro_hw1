all: intl intr

intl: myfunc.o funcs.o
	gcc -Wall -Wl,--wrap,funcReplaced -Wl,--wrap,endFunc -o intl main.o funcs.o myfunc.o

myfunc.o: myfunc.c
	gcc -c myfunc.c

irtr: mydynamicfunc.so main.o funcs.o
	gcc -L. -o intr main.o -lfuncs -Wl,-rpath,"."

mydynamicfunc.so: mydynamicfunc.c
	gcc -Wall -shared -fpic -o mydynamicfunc.so mydynamicfunc.c -ldl

clean:
	rm -rf myfunc.o intl mydynamicfunc.so intr
