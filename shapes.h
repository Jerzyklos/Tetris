#ifndef SHAPE_H
#define SHAPE_H
#include <QColor>

//a point with it's coordinates
struct Point {
    int x,y;
};

//virtual class-parent of all the shapes
class Shape
{
public:
    Shape(int g_id, QColor g_color);
    QColor GetColor();
    int GetID();
    //methods required to be implemented by children
    virtual Point* GetPoints(int& how_many) = 0;
    virtual void Rotate() = 0;
private:
    QColor color;
    int id;
};

//simple square 2x2
class Square : public Shape{
public:
    Square(int g_id, QColor g_color);
    Point* GetPoints(int& how_many);
    //method purposely empty ;)
    void Rotate();
private:
    static int points_num;
    Point points[4];
};

//line 1x3
class Line : public Shape{
public:
    Line(int g_id, QColor g_color);
    Point* GetPoints(int& how_many);
    void Rotate();
private:
    static int points_num;
    Point points[3];
};

//upside down l-shape heading right direction
class L_Shape1 : public Shape{
public:
    L_Shape1(int g_id, QColor g_color);
    Point* GetPoints(int& how_many);
    void Rotate();
private:
    static int points_num;
    Point points[4];
};

//upside down l-shape heading left direction
class L_Shape2 : public Shape{
public:
    L_Shape2(int g_id, QColor g_color);
    Point* GetPoints(int& how_many);
    void Rotate();
private:
    static int points_num;
    Point points[4];
};

#endif // SHAPE_H

