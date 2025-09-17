#pragma once
#include<raylib-cpp.hpp>

class Test_Circle{

public:
    
    Test_Circle(int radius, raylib::Vector2 Position);
    void Draw();
    raylib::Vector2 Update(raylib::Vector2 PointPosition);
    int radius;
    raylib::Vector2 Position;

private:
    bool WithinCircle(raylib::Vector2 Point);

};