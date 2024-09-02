#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
//#include <QGroupBox>
//#include <QComboBox>

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
    QMessageBox msg;
    QAbstractButton* msg_btn;
private Q_SLOTS:
 void button_toggled(bool checked);
 void radio_button_released();
 void radio_button_released_2();
 void msg_clicked_button();

};
#endif // MAINWINDOW_H
