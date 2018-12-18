#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
//#include <QtGui>

class Game;
class Board;
class QPushButton;
class QRect;
class QLabel;

//class containing all the displayed items
class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(Game *g_game, QWidget *parent = nullptr);
    explicit Window(){}
    //displaying window's content
    virtual void paintEvent(QPaintEvent * event);
protected:
    //if a key id pressed
    void keyPressEvent(QKeyEvent *event);
private:
    Board *board;
    QPushButton *button;
    QLabel *label;
    Game *game;
    QRect *rect;
    QTimer *timer;
signals:
private slots:
    //functions required for SLOT mechanism, call Game methods
    void StartGame();
    void NextStep();
};

#endif // WINDOW_H


