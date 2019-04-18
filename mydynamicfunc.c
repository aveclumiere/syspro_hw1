#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void funcReplaced(){
  void (*funcReplacedp)() = NULL;
  char* error;

  funcReplacedp = dlsym(RTLD_NEXT, "funcReplaced");
  if((error = dlerror()) != NULL){
    fputs(error, stderr);
    exit(1);
  }
  funcReplacedp();
  printf("In wrap_funcReplaced\n");
}

void endFunc(){
  void (*endFuncp)() = NULL;
  char* error;

  endFuncp = dlsym(RTLD_NEXT, "endFunc");
  if((error = dlerror()) != NULL){
    fputs(error, stderr);
    exit(1);
  }
  endFuncp();
  printf("In wrap_endFunc\n");
}
