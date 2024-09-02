#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Мощная игра в прогресс");
    //ui->centralwidget->setWindowTitle("Мощная игра");
    msg_btn = msg.addButton(QMessageBox::StandardButton::Ok);
    msg.setIcon(QMessageBox::Icon::Information);
    msg.setText("Game Over");
    ui->groupBox->setTitle("Бокс с кнопками");
    ui->radioButton->setText("Прогресс 1");
    ui->radioButton_2->setText("Прогресс 2");
    //for(int i = 0; i < 6; ++i){
   //     QString temp = "Элемент " + QString::number(i);
   //     ui->comboBox->addItem(temp);
   // }
    ui->pushButton->setText("Прогрессировать");
    ui->pushButton->setCheckable(true);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    //ui->comboBox->addItem("10");
    //ui->comboBox->addItem("15");
    //ui->comboBox->addItem("20");
    //ui->comboBox->addItem("25");
    ui->radioButton->click(); radio_button_released();
    connect(ui->pushButton, &QPushButton::toggled, this, &MainWindow::button_toggled);
    connect(ui->radioButton, &QRadioButton::released, this, &MainWindow::radio_button_released);
    connect(ui->radioButton_2, &QRadioButton::released, this, &MainWindow::radio_button_released_2);
    connect(msg_btn, &QAbstractButton::clicked, this, &MainWindow::msg_clicked_button);
    //connect(ui->comboBox)
    //connect(ui->progressBar, &QProgressBar)


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_toggled(bool checked){
   // qDebug() << Q_FUNC_INFO << checked;
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->comboBox->setEnabled(false);

    if(ui->progressBar->value() < 100) {
        if((ui->comboBox->currentText()).toInt() + ui->progressBar->value() > 100) ui->progressBar->setValue(100);
        else ui->progressBar->setValue((ui->comboBox->currentText()).toInt() + ui->progressBar->value());
    if(ui->progressBar->value() == 100) msg.show();


    }

}

void MainWindow::radio_button_released(){

ui->comboBox->clear();
ui->comboBox->addItem("10");
ui->comboBox->addItem("15");

}

void MainWindow::radio_button_released_2(){

    ui->comboBox->clear();
    ui->comboBox->addItem("20");
    ui->comboBox->addItem("25");
}

void MainWindow::msg_clicked_button(){

    ui->progressBar->setValue(0);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->comboBox->setEnabled(true);
}
