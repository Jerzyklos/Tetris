#include <QApplication>
#include "window.h"
#include "game.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    Game game;
    Window window(&game);

    window.show();
    app.exec();
}


