#include "Grid.h"
#include <QKeyEvent>
#include <QToolButton>
#include <QLayout>

Grid::Grid(QWidget *parent): QWidget(parent){

    for (int i = 0 ; i < 3;i++){
        for (int j=0 ; j<3 ;j++){
            auto& btn = buttons[i*3+j];
            layout.addWidget(&btn,i,j);
        }
    }
    this->setLayout(&layout);
}
