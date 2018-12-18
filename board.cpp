#include "board.h"
#include "rect.h"
#include <QPainter>
#include <QBrush>

Board::Board(int width, int x_margin, int y_margin, Window *g_window)
{
    window=g_window;

    tiles = new Rect*[10];
    for(int i=0; i<10; i++){
        tiles[i] = new Rect[16];
    }
    //creates 10x16 tiles (w x h), where height is width*1.6 AND sets all the tiles as not occupied
    int side=width/10;
    for(int i=0; i<10; i++){
        for(int j=0; j<16; j++){
            tiles[i][j]= Rect(x_margin+i*side, y_margin+j*side, side, side, QColor(Qt::black));
        }
    }
}

Rect **Board::GetTiles() {return tiles;}

//actualizes board's tiles colors
void Board::Actualize(QColor **colors){
    for(int i=0; i<10; i++){
        for(int j=0; j<16; j++){
            tiles[i][j].color=colors[i][j];
        }
    }
    window->update();
}

//destructing an array
Board::~Board(){
    for(int i=0; i<10; i++){
        delete[] tiles[i];
    }
    delete[] tiles;
}

