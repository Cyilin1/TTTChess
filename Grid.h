#ifndef GRID_H
#define GRID_H

#include <QToolButton>
#include <QLayout>
#include <QWidget>


class Grid : public QWidget
{
    Q_OBJECT

public:
    QToolButton buttons[9];
    QGridLayout layout;
    Grid(QWidget *parent = 0);
    //~Grid();
public slots:

};

#endif // GRID_H
