#include "PaintedWidget.h"

#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>

bool flag = true;

PaintedWidget::PaintedWidget()
{
        resize(800, 600);
        setWindowTitle(tr("Paint Demo"));

        for (int i = 0 ; i < 3;i++){
            for (int j=0 ; j<3 ;j++){
                auto& btn = buttons[i*3+j];
                layout.addWidget(&btn,i,j);
            }
        }

        layout.addWidget(&PB,4,3);
        PB.setText("ReStart");
        label.setText("Happy Game");

        QFont ft;
        ft.setPointSize(30);
        label.setFont(ft);

        layout.addWidget(&label,5,5);
        connect(&PB,&QPushButton::clicked,this,&PaintedWidget::Clear);
        this->setLayout(&layout);
}

void PaintedWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier){
        if(event->key() == Qt::Key_M)
            setWindowState(Qt::WindowMaximized);
    }
    else if(event->key() == Qt::Key_1){
        flag = !flag;
        if(flag == true)
            buttons[0].setText("O");

        else
            buttons[0].setText("X");

        IsWinner();
    }
    else if(event->key() == Qt::Key_2){
        flag = !flag;
        if(flag == true)
            buttons[1].setText("O");
        else
            buttons[1].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_3){
        flag = !flag;
        if(flag == true)
            buttons[2].setText("O");
        else
            buttons[2].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_4){
        flag = !flag;
        if(flag == true)
            buttons[3].setText("O");
        else
            buttons[3].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_5){
        flag = !flag;
        if(flag == true)
            buttons[4].setText("O");
        else
            buttons[4].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_6){
        flag = !flag;
        if(flag == true)
            buttons[5].setText("O");
        else
            buttons[5].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_7){
        flag = !flag;
        if(flag == true)
            buttons[6].setText("O");
        else
            buttons[6].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_8){
        flag = !flag;
        if(flag == true)
            buttons[7].setText("O");
        else
            buttons[7].setText("X");
        IsWinner();
    }
    else if(event->key() == Qt::Key_9){
        flag = !flag;
        if(flag == true)
            buttons[8].setText("O");
        else
            buttons[8].setText("X");
        IsWinner();
    }
    else QWidget::keyPressEvent(event);
}

void PaintedWidget::IsWinner(){
    if(buttons[0].text() == "O" && buttons[1].text() == "O" && buttons[2].text() == "O")
            label.setText("Win!!");
    else if(buttons[0].text() == "X" && buttons[1].text() == "X" && buttons[2].text() == "X")
            label.setText("Win!!");
    else if(buttons[0].text() == "X" && buttons[3].text() == "X" && buttons[5].text() == "X")
            label.setText("Win!!");
    else if(buttons[0].text() == "O" && buttons[3].text() == "O" && buttons[5].text() == "O")
            label.setText("Win!!");
    else if(buttons[1].text() == "X" && buttons[4].text() == "X" && buttons[7].text() == "X")
            label.setText("Win!!");
    else if(buttons[1].text() == "O" && buttons[4].text() == "O" && buttons[7].text() == "O")
            label.setText("Win!!");
    else if(buttons[3].text() == "O" && buttons[4].text() == "O" && buttons[5].text() == "O")
            label.setText("Win!!");
    else if(buttons[3].text() == "X" && buttons[4].text() == "X" && buttons[5].text() == "X")
            label.setText("Win!!");
    else if(buttons[2].text() == "X" && buttons[5].text() == "X" && buttons[8].text() == "X")
            label.setText("Win!!");
    else if(buttons[2].text() == "O" && buttons[5].text() == "O" && buttons[8].text() == "O")
            label.setText("Win!!");
    else if(buttons[6].text() == "O" && buttons[7].text() == "O" && buttons[8].text() == "O")
            label.setText("Win!!");
    else if(buttons[5].text() == "X" && buttons[7].text() == "X" && buttons[8].text() == "X")
            label.setText("Win!!");
}

void PaintedWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter   painter(this);//??????QPainter??????
    painter.setRenderHint(QPainter::Antialiasing);//
    painter.setRenderHint(QPainter::TextAntialiasing);//
    //??????????????????5????????????,??????????????????????????????
    qreal R = 100; //??????    //?????????????????????qreal ???windows ?????????double ??????????????????float?????????
    const qreal Pi = 3.1415926;
    qreal deg = Pi * 72/180;
    QPoint points[5] = {
        QPoint(R,0),
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
    //Qt::NoPen,Qt::SolidLine, Qt::DashLine, Qt::DotLine,Qt::DashDotLine,Qt::DashDotDotLine,Qt::CustomDashLine
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

    //????????????????????????PainterPath?????????????????????
    QPainterPath starPath;
    //MOveto ??????????????????
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);
    starPath.closeSubpath(); //???????????????????????????????????????????????????

//    starPath.addText(points[0],font,"0"); //??????????????????
//    starPath.addText(points[1],font,"1");
//    starPath.addText(points[2],font,"2");
//    starPath.addText(points[3],font,"3");
//    starPath.addText(points[4],font,"4");

    //??????
//    painter.save(); //??????????????????
//    painter.translate(100,100);
//    painter.drawPath(starPath); //?????????
//    painter.drawText(0,0,"S1");
//    painter.restore(); //??????????????????

    painter.translate(300,300); //??????
    painter.scale(2,2); //??????
    painter.rotate(55); //???????????????
    painter.drawPath(starPath);//?????????
    //painter.drawText(0,0,"S2");

//    painter.resetTransform(); //????????????????????????
//    painter.translate(700,120); //??????
//    painter.rotate(-145); //???????????????
//    painter.drawPath(starPath);//?????????
//    painter.drawText(0,0,"S3");
}

void PaintedWidget::Clear(){
    buttons[0].setText("");
    buttons[1].setText("");
    buttons[2].setText("");
    buttons[3].setText("");

    buttons[4].setText("");

    buttons[5].setText("");

    buttons[6].setText("");

    buttons[7].setText("");
    buttons[8].setText("");
    label.setText("Happy Game");

}
