#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

private:
    Ui::MainWindow *ui;
    StopWatch* sw;


signals:

private Q_SLOTS:
    //Слот для изменения названия кнопки Старт/Стоп при нажатии на кнопку
    void toggle_start_stop_btn();

    void get_timer_value(QTime timer_value);
    void get_round_info(int round_number, QTime round_time);
    void get_round_info(QString str);
    void get_btn_clear_enabled_flag(bool is_btn_clear_enabled);

};
#endif // MAINWINDOW_H
