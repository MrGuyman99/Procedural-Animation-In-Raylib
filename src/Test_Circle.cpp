#include "Test_Circle.hpp"
#include<raylib-cpp.hpp>
#include<imgui.h>

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

raylib::Vector2 Test_Circle::ResetWithinCircle(raylib::Vector2 Point){

    //If Position and the Point's Position are equal
    if(Position == Point){
        return raylib::Vector2(Position.GetX() + radius, Position.GetY());
    }

    //Calculating the Distance Between the Midpoint of the Circle and the given point's position     
    float Point_dx = Point.GetX() - Position.GetX();
    float Point_dy = Point.GetY() - Position.GetY();
    
    //Calculate the Distance from the center to the point
    float distance = std::sqrt(std::pow(Point_dx, 2) + std::pow(Point_dy, 2));

    //Normalizing the direction
    //(I would use a variable called Normalized_Point_Dx or something like that, but I figure it's better practice this way)
    Point_dx = Point_dx / distance; 
    Point_dy = Point_dy / distance;

    //Calculating new position
    Point_dx = Position.GetX() + (Point_dx * static_cast<float>(radius));
    Point_dy = Position.GetY() + (Point_dy * static_cast<float>(radius));

    return{raylib::Vector2(Point_dx, Point_dy)};

}

raylib::Vector2 Test_Circle::Update(raylib::Vector2 PointPosition){

    //If MousePosition is within the Circle, set the circle's center to equal the current mouse position
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){

        Position.SetX(GetMouseX());
        Position.SetY(GetMouseY());

    }
    
    //If PointPosition is NOT within a circle we clamp it to the circle
    if(WithinCircle(PointPosition) == false){

        raylib::Vector2 clamped = ResetWithinCircle(PointPosition);
        PointPosition.SetX(clamped.GetX());
        PointPosition.SetY(clamped.GetY());

    }

    return{PointPosition};

}

void Test_Circle::RenderUI(){
    
    //Simple UI stuff, nothing too complicated
    ImGui::Begin("CircleUI Window");
        ImGui::SliderInt("Radius", &radius, 8, 100);
    ImGui::End();

}

void Test_Circle::Draw(){

    Position.DrawCircle(radius, PURPLE);

}