#include "input.hpp"

int main(){
    input_app user_triangles;
    user_triangles.Run();
    std::cout << user_triangles.Get1Triangle().point1.x << std::endl;
    std::cout << user_triangles.Get1Triangle().point1.y << std::endl;
}