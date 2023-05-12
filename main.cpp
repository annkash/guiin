#include "GUI.hpp"

int main(){
    UserInterface window;
    window.Run();
    //check correct data
    std::cout << window.Get1Triangle().point1.x << std::endl;
    std::cout << window.Get1Triangle().point1.y << std::endl;
}