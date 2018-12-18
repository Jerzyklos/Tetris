#include "game.h"
#include "board.h"
#include "shapes.h"
#include <iostream>

Game::Game() : board(nullptr) {
    score=0;
    shapefactory = ShapeFactory::GetShapeFactory();
    current_shape=nullptr;

    occupied = new int*[10];
    colors = new QColor*[10];
    for(int i=0; i<10; i++){
        occupied[i]= new int[16];
        colors[i]= new QColor[16];
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<16; j++){
            occupied[i][j]=0;
            colors[i][j]=QColor(0,0,0);
        }
    }
}

Game::~Game(){
   for(int i=0; i<10; i++){
       delete[] occupied[i];
       delete[] colors[i];
   }
   delete[] occupied;
   delete[] colors;
}

void Game::SetBoard(Board *g_board){
    board=g_board;
}

void Game::Start(){
    started=true;
}

bool Game::GameStarted(){
    return started;
}

int Game::GetScore(){
    return score;
}

//moves current_shape down, if it's possible, if not, checks for a complete line
void Game::MoveDown(){
    //if there's no moving shape
    if(current_shape==nullptr) current_shape=shapefactory->MakeShape();

    int points_number=0;
    Point* points=current_shape->GetPoints(points_number);
    bool can_move=true;

    //j will later indicate where the shape stopped, therefore where a line can be complete
    int j;
    for(j=0; j<points_number; j++){
        if((points[j].y<-1) || (points[j].y<15 && (occupied[points[j].x][points[j].y+1]==0 || occupied[points[j].x][points[j].y+1]==current_shape->GetID()))) continue;
        else { can_move=false; std::cout<<"info: coord "<<points[j].x<<" "<<points[j].y<<" down "<<occupied[points[j].x][points[j].y+1]<<"\n"; break;}
    }

    if(can_move){
        for(int i=0; i<points_number; i++){
            if(points[i].y>=-1){
                //writing new tiles
                occupied[points[i].x][points[i].y+1]=current_shape->GetID();
                colors[points[i].x][points[i].y+1]=current_shape->GetColor();

                //emptying old tiles
                occupied[points[i].x][points[i].y]=0;
                colors[points[i].x][points[i].y]=QColor(0,0,0);
                }
            points[i].y++;
        }
    }
    else{
        //checking if the line is complete
        bool line_complete=true;
        int heigth = points[j].y;
        while(line_complete){
            //checking of the line is complete
            for(int i=0; i<10; i++){
                if(occupied[i][heigth]==0){line_complete=false; break;}
            }
            if(line_complete){
                std::cout<<"line complete\n";
                for(int i=0; i<10; i++){
                    for(int j=heigth; j>=1; j--){
                        std::cout<<"to "<<j<<" gives "<<j-1<<"\n";
                        occupied[i][j]=occupied[i][j-1];
                        colors[i][j]=colors[i][j-1];
                    }
                    occupied[i][0]=0;
                    colors[i][0]=QColor(0,0,0);
                    score+=5;
                }
            }
        }
        current_shape=nullptr;
    }
    board->Actualize(colors);
}

//right dir=1, left dir=-1
void Game::MoveToTheSide(int dir){
    if(current_shape!=nullptr){
        int points_number=0;
        Point* points=current_shape->GetPoints(points_number);
        bool can_move=true;

        for(int i=0; i<points_number; i++){
            if((points[i].x<9 && dir==1) || (points[i].x>0 && dir==-1)){
                if(occupied[points[i].x+dir][points[i].y]==0 || occupied[points[i].x+dir][points[i].y]==current_shape->GetID()) continue;
                else{ can_move=false; break;}
            }
            else{ can_move=false; break;}
        }

        if(can_move){
            for(int i=0; i<points_number; i++){
                //emptying old tiles
                    occupied[points[i].x][points[i].y]=0;
                    colors[points[i].x][points[i].y]=QColor(0,0,0);
                }
            for(int i=0; i<points_number; i++){
                //writing new tiles
                points[i].x+=dir;
                occupied[points[i].x][points[i].y]=current_shape->GetID();
                colors[points[i].x][points[i].y]=current_shape->GetColor();
            }

        }
        board->Actualize(colors);
    }
}

void Game::Rotate_Shape(){
    current_shape->Rotate();
    for(int i=0; i<10; i++){
        for(int j=0; j<16; j++){
            if(occupied[i][j]==current_shape->GetID()){
                occupied[i][j]=0;
                colors[i][j]=QColor(0,0,0);
            }
        }
    }
    int points_number=0;
    Point* points=current_shape->GetPoints(points_number);
    for(int i=0; i<points_number; i++){
        occupied[points[i].x][points[i].y]=current_shape->GetID();
        colors[points[i].x][points[i].y]=current_shape->GetColor();
    }
    board->Actualize(colors);
}







