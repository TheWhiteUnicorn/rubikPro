#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "camera.h"
#include "welcome.h"
#include "Master.h"
#include "mainwindow.h"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // код для внесения приложения в реестр
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    //конец кода внесения приложения в реестр
    //создаем объекты окон
    MainWindow w;
    Welcome welcomeWindow;
    //
    //показываем объекты окон
    w.show();
    //проверка на галочку, если нет, то откроется окно приветствия
    if (!settings.value(SETTINGS_WELCOME, false).toBool())
    welcomeWindow.show();

    //Camera();
    /*QPixmap *pixmap = new QPixmap;
    pixmap->load(frame);
    label->setPixmap(*pixmap);*/
    return a.exec();
}

