#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void funcReplaced(){
  void* (funcReplacedp)();
  char* error;

  funcReplacedp = dlsym(RTND_NEXT, "funcReplaced");
  if((error = dlerror()) != NULL){
    fputs(error, stderr);
    exit(1);
  }
  funcReplacedp();
  printf("In wrap_funcReplaced\n");
}

void endFunc(){
  void* (endFuncp)();
  char* error;

  endFuncp = dlsym(RTND_NEXT, "endFunc");
  if((error = dlerror()) != NULL){
    fputs(error, stderr);
    exit(1);
  }
  endFuncp();
  printf("In wrap_endFunc\n");
}
