#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "welcome.h"
//#include "..Cube/Master.h"
#include "cube
#include "QList"
#include "list"
#include "res.hpp"

#define COLOR "QPushButton{background-color: blue;}"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWindow = new Dialog();
    connect(sWindow, &Dialog::firstWindow, this, &MainWindow::show);
    // ужас который я не вынес в отдельные функции, но которые должны тут быть

    // для цвета
    //string m = "Qt::white"; Сделать чтоб цвет был в переменной и подставлялся нужный цвет в нужный момент,
    // возможно поможет функция convertToColors (Color edge, QColor oneColor)
    QColor Color = Qt::white;
    QString ColorName = Color.name();
    // массив указателей на фреймы
    QList<QFrame *> allQFrame = ui->centralwidget->findChildren<QFrame *>();
    // сортируется по возрастанию
    sort(allQFrame.begin(), allQFrame.end(), [] (const QFrame* a , const QFrame* b) { return a->objectName() < b->objectName(); });
    // копия указателей на фреймы, в нормальном виде (грань\строка\столбец)
    QFrame * mainFrames[6][3][3];
    int count = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                mainFrames[i][j][k] = allQFrame[count];
                count++;
            }
        }
    }
    // выставление в белый всех фреймов
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                mainFrames[i][j][k]->setStyleSheet("QFrame{background-color:"  + ColorName + ";}");
                count++;
            }
        }
    }
    Cube cube;
    cube.trick(20);
    //cube.rotate(0,0);
    //cube.rotate(1,0);
    //cube.rotate(2,0);
    //cube.rotate(3,0);
    //cube.rotate(4,0);
    //cube.rotate(5,0);
    //cube.get_edges();

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                //
                switch (cube.get_edges()[i][j][k]) {
                                case 0:
                                    Color=Qt::white;
                                    ColorName=Color.name();
                                    goto setcolor;
                                case 1:
                                    Color.setRgb(255,165,0);
                                    ColorName=Color.name();
                                    goto setcolor;
                                case 2:
                                    Color=Qt::green;
                                    ColorName=Color.name();
                                    goto setcolor;
                                case 3:
                                    Color=Qt::red;
                                    ColorName=Color.name();
                                    goto setcolor;
                                case 4:
                                    Color=Qt::blue;
                                    ColorName=Color.name();
                                    goto setcolor;
                                case 5:
                                    Color=Qt::yellow;
                                    ColorName=Color.name();
                                    goto setcolor;
                                default:
                                    break;
                //
                setcolor:
                mainFrames[i][j][k]->setStyleSheet("QFrame{background-color:"  + ColorName + ";}");
                //mainFrames[6][3][3]->setStyleSheet("QFrame{background-color: black");
            }
        }
    }

    //конец ужаса (но это не точно)
}
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   sWindow->show();
   //this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    Camera();
}

void MainWindow::on_pushButton_3_clicked()
{
    delete ui->frame;
}

void MainWindow::on_pushButton_4_clicked()
{

}


/*string convertToColors(Color edge, QColor *oneColor) МБ Работает, но это не точно
{
    value = edge;
    switch (value) {
    case 0:
        return &oneColor=Qt::white;
        break;
    case 1:
        return &oneColor=Qt::orange";
        break;
    case 2:
        return &oneColor=Qt::green";
        break;
    case 3:
        return &oneColor=Qt::red";
        break;
    case 4:
        return &oneColor=Qt::blue";
        break;
    case 5:
        return &oneColor=Qt::yellow";
        break;
    default:
        break;
}*/
