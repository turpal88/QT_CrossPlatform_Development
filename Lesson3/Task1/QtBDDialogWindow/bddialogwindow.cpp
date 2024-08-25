#include "bddialogwindow.h"
#include "ui_bddialogwindow.h"

BDDialogWindow::BDDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDDialogWindow)
{
    ui->setupUi(this);

    btn = msg.addButton(QMessageBox::StandardButton::Cancel);

}

BDDialogWindow::~BDDialogWindow()
{
    delete ui;
    delete btn;
}

void BDDialogWindow::clear_all_text_fields(){

    ui->bd_name_line_edit->clear();
    ui->host_line_edit->clear();
    ui->login_line_edit->clear();
    ui->password_line_edit->clear();
    ui->port_spin_box->setValue(5432);

    host_name.clear();
    bd_name.clear();
    login.clear();
    password.clear();
    port = 5432;

}
void BDDialogWindow::on_back_to_main_window_button_clicked()
{

    clear_all_text_fields();
    this->close();
}


void BDDialogWindow::on_host_line_edit_clear_clicked()
{
    ui->host_line_edit->clear();

}


void BDDialogWindow::on_bd_name_line_edit_clear_clicked()
{
    ui->bd_name_line_edit->clear();
}


void BDDialogWindow::on_login_line_edit_clear_clicked()
{
    ui->login_line_edit->clear();
}


void BDDialogWindow::on_password_line_edit_clear_clicked()
{
    ui->password_line_edit->clear();
}


void BDDialogWindow::on_port_line_edit_clear_clicked()
{


    ui->port_spin_box->clear();
}


void BDDialogWindow::on_connect_BD_button_released()
{
if(host_name.isEmpty() || bd_name.isEmpty() || login.isEmpty() || password.isEmpty() || port == 0){
    msg.setIcon(QMessageBox::Warning);
    msg.setWindowTitle("Предупреждение");

    if(host_name.isEmpty()){
        msg.setText("Недопустимое имя хоста");
        //msg.addButton();
        msg.show();

    }
    else if(bd_name.isEmpty()){
            msg.setText("Недопустимое имя базы данных");
            //msg.addButton();
            msg.show();

        }
    else if(login.isEmpty()){
            msg.setText("Недопустимый логин");
            //msg.addButton();
            msg.show();

        }
    else if(password.isEmpty()){
            msg.setText("Недопустимый пароль");
            //msg.addButton();
            msg.show();

        }
    else if(port == 0){
            msg.setText("Недопустимый порт");
            //msg.addButton();
            msg.show();

        }

}else connect_to_db();



}

void BDDialogWindow::connect_to_db(){

    db = QSqlDatabase::addDatabase("QPSQL");
        db.setDatabaseName(bd_name);
        db.setHostName(host_name);
        db.setPort(port);
        db.setUserName(login);
        db.setPassword(password);
        db.open();
        if(db.isOpen()){

            msg.setIcon(QMessageBox::Information);
            msg.setWindowTitle("Оповещение");
            msg.setText("Подключение к базе данных успешно произведено");
            msg.show();

        }else{
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle("Ошибка");
        msg.setText("Не удалось подключиться к базе данных");
        msg.show();
}

}


void BDDialogWindow::on_host_line_edit_editingFinished()
{
    host_name = ui->host_line_edit->text();
}


void BDDialogWindow::on_bd_name_line_edit_editingFinished()
{
    bd_name = ui->bd_name_line_edit->text();
}


void BDDialogWindow::on_login_line_edit_editingFinished()
{
    login = ui->login_line_edit->text();
}


void BDDialogWindow::on_password_line_edit_editingFinished()
{
    password = ui->password_line_edit->text();
}


void BDDialogWindow::on_port_spin_box_editingFinished()
{
    port = ui->port_spin_box->value();
}

