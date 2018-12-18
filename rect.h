#ifndef RECT_H
#define RECT_H

#include <QRect>
#include <QColor>

class QColor;
//class for helping board storing rect coordinates and a color
class Rect
{
public:
    Rect(int left=0, int top=0, int width=0, int height=0, QColor g_color=QColor(0,0,0));
    QRect rect;
    QColor color;
};

#endif // RECT_H
