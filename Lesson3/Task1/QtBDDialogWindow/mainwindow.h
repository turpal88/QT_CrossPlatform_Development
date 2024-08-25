#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "bddialogwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void monitor_bd_dialog_window();

private slots:
    void on_actionopen_bd_dialog_window_triggered();

private:
    Ui::MainWindow *ui;
    BDDialogWindow bd_dialog_window;



};
#endif // MAINWINDOW_H
