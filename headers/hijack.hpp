#include <iostream>
#include <dlfcn.h>
#include <cstdio>
extern "C" void start();
extern "C" void numbers(int , int);

typedef void (*hj_t)();
typedef int (*l_fn)(int x, int y);
const char *l_name = "./libmain.so";