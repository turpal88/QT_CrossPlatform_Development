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


Q_SIGNALS:
//void btn_stop_start_released(QString str);
void init_start_stop_btn_title(QString start_stop_btn_title);
private Q_SLOTS:

    void start_stop_btn_toggle(QString str);
    void get_timer_value(QTime timer_value);
    void get_round_info(int round_number, QTime round_time);
    void get_btn_clear_round_enabled_flag(bool is_btn_clear_enabled, bool is_btn_round_enabled);
    void clear_round_field_info();
};
#endif // MAINWINDOW_H
