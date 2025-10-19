#pragma once
#include<raylib-cpp.hpp>

//Inherting LeaderCircle's functions + Variables
//There is literally no exclusive code for Follow_Circle and No Follow_Circle.cpp
//All this does is constrain a point without following the player's mouse
class Follow_Circle : public LeaderCircle{

    public:
        //Uses the leaderCircle constructor
        Follow_Circle(int radius, raylib::Vector2 Position, const char* ImGui_Name) : LeaderCircle(radius, Position, ImGui_Name){}

};