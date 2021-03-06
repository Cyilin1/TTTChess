#include "MainWindow.hpp"
#include "ui_mainwindow.h"


#include <QKeyEvent>
#include <QToolButton>
#include <QLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>


//bool flag = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800,600);
    //    connect(ui->pushButton,&QPushButton::clicked,this,[&ui->toolButton1](){
//        ui->toolButton_1->setText("");
//    });
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::Clear);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//    if(event->modifiers() == Qt::ControlModifier){
//        if(event->key() == Qt::Key_M)
//            setWindowState(Qt::WindowMaximized);
//    }
//    else if(event->key() == Qt::Key_1){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_1->setText("O");

//        else
//            ui->toolButton_1->setText("X");

//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_2){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_2->setText("O");
//        else
//            ui->toolButton_2->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_3){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_3->setText("O");
//        else
//            ui->toolButton_3->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_4){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_4->setText("O");
//        else
//            ui->toolButton_4->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_5){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_5->setText("O");
//        else
//            ui->toolButton_5->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_6){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_6->setText("O");
//        else
//            ui->toolButton_6->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_7){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_7->setText("O");
//        else
//            ui->toolButton_7->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_8){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_8->setText("O");
//        else
//            ui->toolButton_8->setText("X");
//        IsWinner();
//    }
//    else if(event->key() == Qt::Key_9){
//        flag = !flag;
//        if(flag == true)
//            ui->toolButton_9->setText("O");
//        else
//            ui->toolButton_9->setText("X");
//        IsWinner();
//    }
//    else QWidget::keyPressEvent(event);
//}


//void MainWindow::IsWinner(){
//    if(ui->toolButton_1->text() == "O" && ui->toolButton_2->text() == "O" && ui->toolButton_3->text() == "O")
//            ui->label->setText("Win!!");
//    else if(ui->toolButton_1->text() == "X" && ui->toolButton_2->text() == "X" && ui->toolButton_3->text() == "X")
//        ui->label->setText("Win");
//    else if(ui->toolButton_1->text() == "X" && ui->toolButton_4->text() == "X" && ui->toolButton_7->text() == "X")
//        ui->label->setText("Win");
//    else if(ui->toolButton_1->text() == "O" && ui->toolButton_4->text() == "O" && ui->toolButton_7->text() == "O")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_2->text() == "X" && ui->toolButton_5->text() == "X" && ui->toolButton_8->text() == "X")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_2->text() == "O" && ui->toolButton_5->text() == "O" && ui->toolButton_8->text() == "O")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_4->text() == "O" && ui->toolButton_5->text() == "O" && ui->toolButton_6->text() == "O")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_4->text() == "X" && ui->toolButton_5->text() == "X" && ui->toolButton_6->text() == "X")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_3->text() == "X" && ui->toolButton_6->text() == "X" && ui->toolButton_9->text() == "X")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_3->text() == "O" && ui->toolButton_6->text() == "O" && ui->toolButton_9->text() == "O")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_7->text() == "O" && ui->toolButton_8->text() == "O" && ui->toolButton_9->text() == "O")
//        ui->label->setText("Win!!");
//    else if(ui->toolButton_7->text() == "X" && ui->toolButton_8->text() == "X" && ui->toolButton_9->text() == "X")
//        ui->label->setText("Win!!");

//}

void MainWindow::Clear(){
    ui->toolButton_1->setText("");
    ui->toolButton_2->setText("");
    ui->toolButton_3->setText("");
    ui->toolButton_4->setText("");

    ui->toolButton_5->setText("");

    ui->toolButton_6->setText("");

    ui->toolButton_7->setText("");

    ui->toolButton_8->setText("");
    ui->toolButton_9->setText("");
    ui->label->setText("Happy Game");

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter    painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//
    painter.setRenderHint(QPainter::TextAntialiasing);//

    qreal R = 100;
    const qreal Pi = 3.1415926;
    qreal deg = Pi * 72/180;
    QPoint points[5] = {
        QPoint(0,0),
        QPoint(R*cos(deg),-R*sin(deg)),
        QPoint(R*cos(2*deg),-R*sin(2*deg)),
        QPoint(R*cos(3*deg),-R*sin(3*deg)),
        QPoint(R*cos(4*deg),-R*sin(4*deg)),
    };


    //????????????
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);


    //????????????
    QPen penLine;
    penLine.setWidth(2);//??????
    penLine.setColor(Qt::blue); //????????????
    penLine.setStyle(Qt::SolidLine);//?????????????????????????????????
    //Qt::FlatCap, Qt::SquareCap,Qt::RoundCap
    penLine.setCapStyle(Qt::FlatCap);//???????????????
    //Qt::MiterJoin,Qt::BevelJoin,Qt::RoundJoin,Qt::SvgMiterJoin
    penLine.setJoinStyle(Qt::BevelJoin);//?????????????????????
    painter.setPen(penLine);

    //????????????
    QBrush  brush;
    brush.setColor(Qt::red); //????????????
    brush.setStyle(Qt::SolidPattern); //??????????????????
    painter.setBrush(brush);  //

    QPainterPath starPath;
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);
    starPath.closeSubpath(); //???????????????????????????????????????????????????

    starPath.addText(points[0],font,"0"); //??????????????????
    starPath.addText(points[1],font,"1");
    starPath.addText(points[2],font,"2");
    starPath.addText(points[3],font,"3");
    starPath.addText(points[4],font,"4");

    //??????
    painter.save(); //??????????????????
    painter.translate(100,120);
    painter.drawPath(starPath); //?????????
    painter.drawText(0,0,"S1");
    painter.restore(); //??????????????????

    painter.translate(300,120); //??????
    painter.scale(0.8,0.8); //??????
    painter.rotate(30); //???????????????
    painter.drawPath(starPath);//?????????
    painter.drawText(0,0,"S2");

    painter.resetTransform(); //????????????????????????
    painter.translate(500,120); //??????
    painter.rotate(-145); //???????????????
    painter.drawPath(starPath);//?????????
    painter.drawText(0,0,"S3");
}
