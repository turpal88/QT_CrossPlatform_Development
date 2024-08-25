#ifndef BDDIALOGWINDOW_H
#define BDDIALOGWINDOW_H

#include <QDialog>
#include <QMessageBox>
//#include <qpushbutton.h>
#include <qabstractbutton.h>
#include <QtSql>

namespace Ui {
class BDDialogWindow;
}

class BDDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BDDialogWindow(QWidget *parent = nullptr);
    ~BDDialogWindow();

    void clear_all_text_fields();
    QSqlDatabase db;
private slots:
    void on_back_to_main_window_button_clicked();

    void on_host_line_edit_clear_clicked();

    void on_bd_name_line_edit_clear_clicked();

    void on_login_line_edit_clear_clicked();

    void on_password_line_edit_clear_clicked();

    void on_port_line_edit_clear_clicked();

    void on_connect_BD_button_released();

    void on_host_line_edit_editingFinished();

    void on_bd_name_line_edit_editingFinished();

    void on_login_line_edit_editingFinished();

    void on_password_line_edit_editingFinished();

    void on_port_spin_box_editingFinished();

private:
    Ui::BDDialogWindow* ui;
    QMessageBox msg;
    QAbstractButton* btn;
    void connect_to_db();
    //Поля для соединения с БД
    QString host_name;
    QString bd_name;
    QString login;
    QString password;
    quint64 port;
};


#endif // BDDIALOGWINDOW_H
