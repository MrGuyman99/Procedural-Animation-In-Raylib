#include "LeaderCircle.hpp"
#include<raylib-cpp.hpp>
#include<imgui.h>

LeaderCircle::LeaderCircle(int radius, raylib::Vector2 Position, const char* ImGui_Name){

    //Setting Global Variables
    this->Position = Position;
    this->radius = radius;
    this->ImGui_Name = ImGui_Name;
}

bool LeaderCircle::WithinCircle(raylib::Vector2 Point){

    //Uses some magic to figure out if a point is within a circle
    double distance_squared = std::pow(Point.GetX() - Position.GetX(), 2) + std::pow(Point.GetY() - Position.GetY(), 2);
    return{distance_squared <= std::pow(radius, 2)};

}

raylib::Vector2 LeaderCircle::ResetWithinCircle(raylib::Vector2 Point){

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
    Point_dx = Point_dx / distance; 
    Point_dy = Point_dy / distance;

    //Calculating new position
    Point_dx = Position.GetX() + (Point_dx * static_cast<float>(radius));
    Point_dy = Position.GetY() + (Point_dy * static_cast<float>(radius));

    return{raylib::Vector2(Point_dx, Point_dy)};

}

raylib::Vector2 LeaderCircle::Update(raylib::Vector2 PointPosition){
    
    //If PointPosition is NOT within a circle we clamp it to the circle
    if(WithinCircle(PointPosition) == false){

        //Using Clamped here so that we don't have to call ResetWithinCircle multiple times
        raylib::Vector2 clamped = ResetWithinCircle(PointPosition);
        PointPosition.SetX(clamped.GetX());
        PointPosition.SetY(clamped.GetY());

    }

    return{PointPosition};

}

void LeaderCircle::Control(){

    //If MousePosition is within the Circle, set the circle's center to equal the current mouse position
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){

        Position.SetX(GetMouseX());
        Position.SetY(GetMouseY());

    }

}

void LeaderCircle::RenderUI(){
    
    //Simple UI stuff, nothing too complicated
    ImGui::Begin(ImGui_Name);
        ImGui::SliderInt("Radius", &radius, 8, 100);
        if(ImGui::Button("Reset", ImVec2(64, 24))){

            Position = raylib::Vector2(GetScreenWidth() / 2, GetScreenHeight() / 2);

        }
    ImGui::End();

}

void LeaderCircle::Draw(){

    Position.DrawCircle(radius, PURPLE);

}