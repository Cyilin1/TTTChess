#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QToolButton>
#include <QLayout>
#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QToolButton buttons[9];
    QGridLayout layout;
    QLabel label;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void IsWinner();
    void Clear();

protected:
    //void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
