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
    Follow_Circle FCircle2(50, raylib::Vector2(300, 200), "Follow Circle2 Window");
    raylib::Vector2 Point(500, 400);

    while(window.ShouldClose() == false){
        
        BeginDrawing();
            
            window.ClearBackground(DARKGRAY);
            FCircle.Position = Circle.Update(FCircle.Position);
            FCircle2.Position = FCircle.Update(FCircle2.Position);
            Point = FCircle2.Update(Point);
            Circle.Draw();
            FCircle.Draw();
            FCircle2.Draw();
            //ONLY Call for Leader circle
            Circle.Control();
            
            Point.DrawCircle(25, PURPLE);
            DrawFPS(3, 3);
            rlImGuiBegin();
                Circle.RenderUI();
                FCircle.RenderUI();
                FCircle2.RenderUI();
            rlImGuiEnd();
        EndDrawing();
    }
}