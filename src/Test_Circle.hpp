#pragma once
#include<raylib-cpp.hpp>

class Test_Circle{

public:
    
    Test_Circle(int radius, raylib::Vector2 Position);
    void Draw();
    void RenderUI();
    raylib::Vector2 Update(raylib::Vector2 PointPosition);
    raylib::Vector2 Position;
    int radius;

private:
    
    raylib::Vector2 ResetWithinCircle(raylib::Vector2 Point);
    bool WithinCircle(raylib::Vector2 Point);

};