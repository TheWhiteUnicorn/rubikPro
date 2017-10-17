#ifndef WELCOME_H
#define WELCOME_H

/* Defining */
#define ORGANIZATION_NAME "CubicPro"
#define ORGANIZATION_DOMAIN "www.cubicpro.ru"
#define APPLICATION_NAME "CubicPro App"
#define SETTINGS_WELCOME "settings\welcome"

#include <QDialog>
#include <QSettings>
#include <QMessageBox>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_checkBox_clicked();

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
