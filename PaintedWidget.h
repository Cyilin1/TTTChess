#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QPushButton>
#include <QToolButton>
#include <QLayout>
#include <QWidget>
#include <QLabel>

class PaintedWidget : public QWidget
{
public:
        PaintedWidget();
        QToolButton buttons[9];
        QGridLayout layout;
        QPushButton PB;
        QLabel label;
        void IsWinner();
        void Clear();
protected:
        void keyPressEvent(QKeyEvent *event);
        void paintEvent(QPaintEvent *event);
};
#endif // PAINTEDWIDGET_H
