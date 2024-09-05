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
    ui->timeEdit->setReadOnly(true);
    ui->timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->timeEdit->setDisplayFormat("H:mm:ss.zzz");
    ui->groupBox->setTitle("Кнопки");
    ui->groupBox_2->setTitle("Время секундомера");

    ui->btn_clear->setEnabled(false);
    ui->btn_round->setEnabled(false);

    connect(this, &MainWindow::init_start_stop_btn_title, sw, &StopWatch::init_start_stop_btn_title);
    connect(ui->btn_start_stop, &QPushButton::released, sw, &StopWatch::toggle_start_stop_btn);
    connect(sw, &StopWatch::start_stop_btn_title_toggled, this, &MainWindow::start_stop_btn_toggle);
    emit init_start_stop_btn_title(ui->btn_start_stop->text());

    connect(sw, &StopWatch::set_timer_value, this, &MainWindow::get_timer_value);
    connect(ui->btn_clear, &QPushButton::released, sw, &StopWatch::btn_clear_release);
    connect(ui->btn_round, &QPushButton::released, sw, &StopWatch::btn_round_release);
    connect(sw, &StopWatch::set_btn_clear_round_enabled_flag, this, &MainWindow::get_btn_clear_round_enabled_flag);
    connect(sw, &StopWatch::set_round_info, this, &MainWindow::get_round_info);
    connect(ui->btn_clear, &QPushButton::released, this, &MainWindow::clear_round_field_info);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::start_stop_btn_toggle(QString str){

    ui->btn_start_stop->setText(str);


}

void MainWindow::get_timer_value(QTime timer_value){
     ui->timeEdit->setTime(timer_value);

}

void MainWindow::get_round_info(int round_number, QTime round_time){
    QString str = "Круг № " + QString::number(round_number) + ". Время круга: " + round_time.toString("H:mm:ss.zzz");
    ui->lineEdit->setText(str);

}

void MainWindow::get_btn_clear_round_enabled_flag(bool is_btn_clear_enabled, bool is_btn_round_enabled){
    ui->btn_clear->setEnabled(is_btn_clear_enabled);
    ui->btn_round->setEnabled(is_btn_round_enabled);

}

void MainWindow::clear_round_field_info(){
ui->lineEdit->clear();
}
