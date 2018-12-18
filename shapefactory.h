#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

class Shape;
//a singletone creating random shapes
//singletone
class ShapeFactory
{
public:
    static ShapeFactory* GetShapeFactory();
    Shape* MakeShape();
private:
    ShapeFactory();
};

#endif // SHAPEFACTORY_H

