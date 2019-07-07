#include <iostream>
#include <dlfcn.h>
int main(){
    void *handle = dlopen("./liboffense.so", RTLD_LAZY);
    typedef void (*dl_t)();
    std::cout <<"Calling functions" << std::endl;
    dl_t start = (dl_t) dlsym(handle, "start");
    start();
    //dlclose(handle);

    //std::cout << "Result is: " << x << std::endl;

}

