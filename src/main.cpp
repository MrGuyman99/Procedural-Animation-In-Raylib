#include "LeaderCircle.hpp"
#include<raylib-cpp.hpp>
#include<rlImGui.h>
#include "Follow_Circle.hpp"

int main(){

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib::Window window(800, 600, "Distance Constraint");
    window.SetTargetFPS(60);
    rlImGuiSetup(true);
    
    LeaderCircle Circle = LeaderCircle(100, raylib::Vector2(500, 400), "Leader Circle Window");
    Follow_Circle FCircle(75, raylib::Vector2(400, 300), "Follow Circle Window");
    raylib::Vector2 Point(500, 400);

    while(window.ShouldClose() == false){
        
        BeginDrawing();
            
            window.ClearBackground(DARKGRAY);
            FCircle.Position = Circle.Update(FCircle.Position);
            Point = FCircle.Update(Point);
            Circle.Draw();
            FCircle.Draw();
            //ONLY Call for Leader circle
            Circle.Control();
            
            Point.DrawCircle(50, PURPLE);
            DrawFPS(3, 3);
            rlImGuiBegin();
                Circle.RenderUI();
                FCircle.RenderUI();
            rlImGuiEnd();
        EndDrawing();
    }
}