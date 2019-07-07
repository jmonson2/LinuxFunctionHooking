#include "../headers/dl.hpp"
extern "C" void start(){
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
    for(int i = 0; i < y; i++){
        x += y;
        std::cout << x << std::endl;
    }
    start();
}
extern "C" int addnums(int x, int y){
    return x+y;
}