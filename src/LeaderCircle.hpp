#pragma once
#include<raylib-cpp.hpp>

class LeaderCircle{

    public:
    
        LeaderCircle(int radius, raylib::Vector2 Position, const char* ImGui_Name);
        void Draw();
        void RenderUI();
        raylib::Vector2 Update(raylib::Vector2 PointPosition);
        raylib::Vector2 Position;
        int radius;    
        raylib::Vector2 ResetWithinCircle(raylib::Vector2 Point);
        bool WithinCircle(raylib::Vector2 Point);
        const char* ImGui_Name;
        void Control();
};