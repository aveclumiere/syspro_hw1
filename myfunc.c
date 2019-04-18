#include <stdio.h>

void __real_funcReplaced();
void __real_endFunc();

void __wrap_funcReplaced(){
  __real_funcReplaced();
  printf("In wrap_funcReplaced\n");
}

void __wrap_endFunc(){
  __real_endFunc();
  printf("In wrap_endFunc\n");
}
