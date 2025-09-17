#include "Test_Circle.hpp"
#include<raylib-cpp.hpp>
#include<iostream>

Test_Circle::Test_Circle(int radius, raylib::Vector2 Position){

    //Setting Global Variables
    this->Position = Position;
    this->radius = radius;

}

bool Test_Circle::WithinCircle(raylib::Vector2 Point){

    //Uses some magic to figure out if a point is within a circle
    double distance_squared = std::pow(Point.GetX() - Position.GetX(), 2) + std::pow(Point.GetY() - Position.GetY(), 2);
    return{distance_squared <= std::pow(radius, 2)};

}

raylib::Vector2 Test_Circle::Update(raylib::Vector2 PointPosition){

    if(WithinCircle(PointPosition) == true && WithinCircle(GetMousePosition()) == true){

        PointPosition.SetX(GetMouseX());
        PointPosition.SetY(GetMouseY());

    }

    return{PointPosition};

}

void Test_Circle::Draw(){

    Position.DrawCircle(radius, PURPLE);

}