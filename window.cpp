#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QPainter>
#include <QBrush>
#include <QtGui>
#include <QString>
#include "window.h"
#include "game.h"
#include "board.h"
#include "rect.h"

//creates and sets the button, the board, the label and the game
Window::Window(Game *g_game, QWidget *parent) : QWidget(parent)
{
    setFixedSize(440, 700);
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    //creating a starting game button
    button = new QPushButton("Graj", this);
    button->setGeometry(0.5*width()-20,height()-40,0.5*width(),35); //pozycja x,y; rozmiar x,y

    //creating score label
    label = new QLabel("Beniz",this);
    label->setGeometry(20, height()-40, 0.5*width()-40, 35);
    QFont font("Helvetica",12);
    font.setPointSize(28);
    label->setFont(font);

    //creates a board with its size, it should be multiplication of 10*16
    int x_margin=20;
    int y_margin=10;
    board = new Board(this->width()-2*x_margin, x_margin, y_margin, this);

    //creates a timer required to call game in order to move down
    timer = new QTimer(this);

    g_game->SetBoard(board);
    game = g_game;

    //connections
    connect(button, SIGNAL(clicked()), this, SLOT(StartGame()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(NextStep()));
}

//displays the window
void Window::paintEvent(QPaintEvent * event){
    label->setText(QString::number(game->GetScore())+" pts");
    QBrush brush(Qt::SolidPattern);
    QPainter painter(this);
    Rect** tiles = board->GetTiles();

    for(int i=0; i<10; i++){
        for(int j=0; j<16; j++){
            brush.setColor(tiles[i][j].color);
            painter.setBrush(brush);
            painter.drawRect(tiles[i][j].rect);
        }
    }
}

//HERE YOU CAN SET THE TEMPO! by adjusting timer value
//also see the connnections in the constructor
void Window::StartGame(){game->Start(); timer->start(200);}

void Window::NextStep(){game->MoveDown();}

void Window::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right) game->MoveToTheSide(1);
    else if(event->key() == Qt::Key_Left) game->MoveToTheSide(-1);
    else if(event->key() == Qt::Key_Down) game->MoveDown();
    else if(event->key() == Qt::Key_Space) game->Rotate_Shape();
}
