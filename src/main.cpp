#include "Test_Circle.hpp"
#include<raylib-cpp.hpp>
#include<iostream>

int main(){

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window window(800, 600, "Distance Constraint");
    window.SetTargetFPS(60);
    Test_Circle Circle = Test_Circle(100, raylib::Vector2(500, 400));
    raylib::Vector2 Point(500, 400);

    while(window.ShouldClose() == false){
        
        BeginDrawing();
            
            window.ClearBackground(DARKGRAY);
            Point.SetX(Circle.Update(Point).GetX());
            Point.SetY(Circle.Update(Point).GetY());
            Circle.Draw();
            Point.DrawCircle(8, GREEN);
            DrawFPS(3, 3);

        EndDrawing();
    }
}