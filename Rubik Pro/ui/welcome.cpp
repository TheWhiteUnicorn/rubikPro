#include "welcome.h"
#include "ui_welcome.h"



Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    //запрашиваем из реестра значение чек-бокса окна приветствия
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    //сли ключ не существует, то будет установлен параметр по умолчанию, то есть false
    ui->checkBox->setChecked(settings.value(SETTINGS_WELCOME, false).toBool());
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_clicked() // При нажатии на кнопку начать! производится сохранение в реестр значение чек бокса больше не показывать
{
    this->close();
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    /* Сохранение информации о включённости функции сворачивания
     * в трей производится в соответствии с состоянием чекбокса.
     * */
    if(ui->checkBox->isChecked()){
        settings.setValue(SETTINGS_WELCOME, true);
    } else {
        settings.setValue(SETTINGS_WELCOME, false);
    }
    settings.sync();

    /* Диалоговое сообщение, которое сигнализирует об успешности
     * сохранения настроек
     * */
//    QMessageBox::information(this,
//                             trUtf8("Сохранение настроек"),
//                             trUtf8("Сохранение настроек выполнено успешно"));
}

void Welcome::on_checkBox_clicked()
{

}
