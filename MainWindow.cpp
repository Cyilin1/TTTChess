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


    //设置字体
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);


    //设置画笔
    QPen penLine;
    penLine.setWidth(2);//线宽
    penLine.setColor(Qt::blue); //划线颜色
    penLine.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
    //Qt::FlatCap, Qt::SquareCap,Qt::RoundCap
    penLine.setCapStyle(Qt::FlatCap);//线端点样式
    //Qt::MiterJoin,Qt::BevelJoin,Qt::RoundJoin,Qt::SvgMiterJoin
    penLine.setJoinStyle(Qt::BevelJoin);//线的连接点样式
    painter.setPen(penLine);

    //设置画刷
    QBrush  brush;
    brush.setColor(Qt::red); //画刷颜色
    brush.setStyle(Qt::SolidPattern); //画刷填充样式
    painter.setBrush(brush);  //

    QPainterPath starPath;
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);
    starPath.closeSubpath(); //闭合路径，最后一个点与第一个点相连

    starPath.addText(points[0],font,"0"); //显示端点编号
    starPath.addText(points[1],font,"1");
    starPath.addText(points[2],font,"2");
    starPath.addText(points[3],font,"3");
    starPath.addText(points[4],font,"4");

    //绘图
    painter.save(); //保存坐标状态
    painter.translate(100,120);
    painter.drawPath(starPath); //画星星
    painter.drawText(0,0,"S1");
    painter.restore(); //恢复坐标状态

    painter.translate(300,120); //平移
    painter.scale(0.8,0.8); //缩放
    painter.rotate(30); //顺时针旋转
    painter.drawPath(starPath);//画星星
    painter.drawText(0,0,"S2");

    painter.resetTransform(); //复位所有坐标变换
    painter.translate(500,120); //平移
    painter.rotate(-145); //逆时针旋转
    painter.drawPath(starPath);//画星星
    painter.drawText(0,0,"S3");
}
