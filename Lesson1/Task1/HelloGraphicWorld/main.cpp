//#include <QApplication>
#include <QtWidgets>
#include <QMessageBox>


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    //MainWindow w;

    QMessageBox msg;
    msg.setText("Hello Graphic World!");
    msg.setWindowTitle("Start Window");
    msg.setStyleSheet("color: black; background-color: rgb(59, 125, 0); font: bold 14px;");
    msg.setIcon(QMessageBox::Information);
    msg.show();

    return a.exec();
    //return 0;
}
