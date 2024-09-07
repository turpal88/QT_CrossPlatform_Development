#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sw = new StopWatch(this);


    this->setWindowTitle("Секундомер");
    ui->btn_start_stop->setText("Старт");
    ui->btn_clear->setText("Очистить");
    ui->btn_round->setText("Круг");
    ui->label->setAlignment(Qt::AlignHCenter);
    ui->label->setText("0:00:00.000");
    ui->textBrowser->setReadOnly(true);

    ui->groupBox->setTitle("Кнопки");
    ui->groupBox_2->setTitle("Время секундомера");



    ui->btn_clear->setEnabled(false);
    ui->btn_round->setEnabled(false);


    connect(ui->btn_start_stop, &QPushButton::released, this, &MainWindow::toggle_start_stop_btn);


    connect(sw, &StopWatch::set_timer_value, this, &MainWindow::get_timer_value);
    connect(ui->btn_clear, &QPushButton::released, sw, &StopWatch::btn_clear_release);
    connect(ui->btn_round, &QPushButton::released, sw, &StopWatch::btn_round_release);
    connect(sw, &StopWatch::set_btn_clear_enabled_flag, this, &MainWindow::get_btn_clear_enabled_flag);
    connect(sw, qOverload<int, QTime>(&StopWatch::set_round_info), this, qOverload<int, QTime>(&MainWindow::get_round_info));
    connect(sw, qOverload<>(&StopWatch::set_round_info), this, qOverload<>(&MainWindow::get_round_info));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggle_start_stop_btn(){
    if(ui->btn_start_stop->text() == "Старт"){
        ui->btn_start_stop->setText("Стоп");
    }
    else if(ui->btn_start_stop->text() == "Стоп"){
       ui->btn_start_stop->setText("Старт");

    }
    sw->start_stop_timer();

}



void MainWindow::get_timer_value(QTime timer_value){
    ui->label->setText(timer_value.toString("H:mm:ss.zzz"));
    //ui->timeEdit->setTime(timer_value);

}

void MainWindow::get_round_info(int round_number, QTime round_time){
    QString str = "Круг № " + QString::number(round_number) + ". Время круга: " + round_time.toString("H:mm:ss.zzz");
    ui->textBrowser->insertPlainText(str + "\n");

}

void MainWindow::get_round_info(){
    ui->textBrowser->clear();
}

void MainWindow::get_btn_clear_enabled_flag(bool is_btn_clear_enabled, bool is_btn_round_enabled){
    ui->btn_clear->setEnabled(is_btn_clear_enabled);
    ui->btn_round->setEnabled(is_btn_round_enabled);


}


