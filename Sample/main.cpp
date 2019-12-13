#include <iostream>
#include "Graphics/Window.h"
#include "Maths/maths.h"

using namespace std;
using namespace TRender;
using namespace Graphics;


int main(){
    if(glfwInit()){
        cout << "glfw init" << endl;
    }
    Window window = Window("win", 600, 800);
    Maths::vec2();
    while (!window.closed())
    {
        window.clear();
        window.update();
    }
    glfwTerminate();
    return 0;
}

