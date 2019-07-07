#include <iostream>
#include <dlfcn.h>

extern "C" void start();
extern "C" void numbers(int , int);

typedef void (*hj_t)();
typedef int (*l_fn)(int x, int y);
