#include "../headers/hijack.hpp"
void __attribute__((constructor)) startup(){
    for(int i = 0; i < 5; i++){
        std::cout << std::endl;
        std::cout << "PROCESS HIJACKED" << std::endl;
    }


    void *handle = dlopen(l_name, RTLD_NOLOAD | RTLD_NOW);
    void *symbol = dlsym(handle, "numbers");
    l_fn l_addnums = (l_fn)dlsym(handle, "addnums");
    int test = l_addnums(1,2);
    std::cout << "Result of addnums : " << test << std::endl;
    std::cout << handle << std::endl;
    
    

};
void __attribute__((destructor)) shutdown();
extern "C" void start(){
    std::cout << "Hijacked Start" << std::endl;
    int x, y;
    std::cout << "Please Enter a Number" << std::endl;
    std::cin >> x;
    std::cout << "Please Enter Another Number" << std::endl;
    std::cin >> y;
    if(x * y == 0)
        return;
    numbers(x,y);
   
}
extern "C" void numbers(int x, int y){
    std::cout << "Hijacked numbers" << std::endl;
    for(int i = 0; i < y; i++){
        x += y;
        std::cout << x << std::endl;
    }
    start();
}

extern "C" int addnums(int x, int y){
    std::cout << "Hijacked addnums" << std::endl;
    return x-y;
}