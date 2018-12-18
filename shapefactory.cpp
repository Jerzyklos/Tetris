#include <cstdlib>
#include <ctime>
#include "shapefactory.h"
#include "shapes.h"

ShapeFactory::ShapeFactory(){}

ShapeFactory* ShapeFactory::GetShapeFactory()
{
    static ShapeFactory singleton;
    return &singleton;
}

//creates a random shape
Shape* ShapeFactory::MakeShape(){
    static int id=0;
    id++;
    srand(time(NULL));
    QColor color=QColor(rand()%255, rand()%255, rand()%255);
    int i=rand()%4;
    if(i==0) return new Square(id, color);
    if(i==1) return new Line(id, color);
    if(i==2) return new L_Shape1(id, color);
    else return new L_Shape2(id, color);
}
