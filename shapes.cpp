#include "shapes.h"
#include <iostream>

int Square::points_num=4;
int Line::points_num=3;
int L_Shape1::points_num=4;
int L_Shape2::points_num=4;

Shape::Shape(int g_id, QColor g_color) : id(g_id), color(g_color) {}

QColor Shape::GetColor(){return color;}

int Shape::GetID(){return id;}

Square::Square(int g_id, QColor g_color) : Shape(g_id, g_color) {
    points[0].x=4;
    points[0].y=-1;
    points[1].x=5;
    points[1].y=-1;
    points[2].x=4;
    points[2].y=-2;
    points[3].x=5;
    points[3].y=-2;
}

void Square::Rotate(){}

Point* Square::GetPoints(int &how_many){
    how_many=points_num; return points;
}

Line::Line(int g_id, QColor g_color) : Shape(g_id, g_color) {
    points[0].x=4;
    points[0].y=-1;
    points[1].x=5;
    points[1].y=-1;
    points[2].x=6;
    points[2].y=-1;
}

void Line::Rotate(){
    static int i_x=0;
    static int i_y=0;
    static int x[]={1, -1, -1, 1};
    static int y[]={1, 1, -1, -1};

    std::cout<<"wsp "<<points[0].x<<" "<<points[0].y<<" zmieniam na ";
    points[0].x+=x[i_x%4];
    points[0].y+=y[i_y%4];
    std::cout<<points[0].x<<" "<<points[0].y<<std::endl;

    std::cout<<"wsp "<<points[2].x<<" "<<points[2].y<<" zmieniam na ";
    points[2].x+=x[2+(i_x%4)];
    points[2].y+=y[2+(i_y%4)];
    std::cout<<points[2].x<<" "<<points[2].y<<std::endl;

    i_x++;
    i_y++;
}

Point* Line::GetPoints(int &how_many){
    how_many=points_num; return points;
}

L_Shape1::L_Shape1(int g_id, QColor g_color) : Shape(g_id, g_color) {
    points[0].x=4;
    points[0].y=-1;
    points[1].x=4;
    points[1].y=-2;
    points[2].x=4;
    points[2].y=-3;
    points[3].x=5;
    points[3].y=-3;
}

void L_Shape1::Rotate(){}

Point* L_Shape1::GetPoints(int &how_many){
    how_many=points_num; return points;
}

L_Shape2::L_Shape2(int g_id, QColor g_color) : Shape(g_id, g_color) {
    points[0].x=5;
    points[0].y=-1;
    points[1].x=5;
    points[1].y=-2;
    points[2].x=5;
    points[2].y=-3;
    points[3].x=4;
    points[3].y=-3;
}

void L_Shape2::Rotate(){}

Point* L_Shape2::GetPoints(int &how_many){
    how_many=points_num; return points;
}


