#include "MainWindow.hpp"
#include "main.moc"
#include "PaintedWidget.h"

#include "Grid.h"
#include <QWidget>
#include <QApplication>
#include <QPaintEvent>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Grid grid;
    //grid.show();
    //MainWindow m;
    //m.show();
    PaintedWidget w;
    w.show();
    return app.exec();
}
