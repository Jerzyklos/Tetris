#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <vector>
#include "window.h"
#include "rect.h"
#include "shapefactory.h"

//class for managing game board, gets informations from Game class
class Board
{
    public:
        Board(int width, int x_margin, int y_margin, Window* g_window);
        Rect **GetTiles();
        void Actualize(QColor** colors);
        ~Board();
    private:
        Window* window;
        //size of the board, 10x16
        Rect** tiles;
};

#endif // BOARD_H
