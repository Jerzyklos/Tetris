#ifndef GAME_H
#define GAME_H
#include "shapefactory.h"
#include "board.h"

//game logic, operates on two arrays representing the game board, occupied and colors
class Game
{
public:
    //setting arrays and score
    Game();
    void SetBoard(Board* g_board);
    void Start();
    bool GameStarted();
    //moves current_shape one tile down, also checks for complete line
    void MoveDown();
    //moves current_shape to the side; right dir=1, left dir=-1
    void MoveToTheSide(int dir);
    //currently unfinished, rotates current_shape
    void Rotate_Shape();
    int GetScore();
    ~Game();
private:
    //if game is started
    bool started;
    //pointer to game board, used to actualize it
    Board* board;
    //factory making random shapes
    ShapeFactory* shapefactory;
    //contains 0's or shape's id on a board, size 10x16
    int** occupied;
    //colors of the board, size 10x16
    QColor** colors;
    Shape* current_shape;
    int score;
};

#endif // GAME_H
