#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionopen_bd_dialog_window_triggered()
{
    bd_dialog_window.clear_all_text_fields();
    bd_dialog_window.show();


}





