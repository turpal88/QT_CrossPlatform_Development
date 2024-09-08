#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sb_initNum->setValue(200000);
    ui->rb_synchOff->setChecked(true);

   race1 = new Controller(&m);
   race2 = new Controller(&m);

   concurRace1 = new ExampleRace(&m);
   concurRace2 = new ExampleRace(&m);

   watcher1 = new QFutureWatcher<void>();
   watcher2 = new QFutureWatcher<void>();


    //Сигналы по завершению работы потоков
    connect(race1, &Controller::sig_WorkFinish, [&](){
        //отображаем только когда второй поток закончит работу
        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                  QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });

    connect(race2, &Controller::sig_WorkFinish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });


    connect(concurRace1, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Получилось число: " + QString::number(number) + ", а ожидалось " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(concurRace2, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Получилось число: " + QString::number(number) + ", а ожидалось " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });




    connect(watcher1, &QFutureWatcher<void>::started, this, [](){
        qDebug() << "Первый поток начал свою работу";
    });

    connect(watcher2, &QFutureWatcher<void>::started, this, [](){
        qDebug() << "Второй поток начал свою работу";
    });

    connect(watcher1, &QFutureWatcher<void>::finished, this, [](){
        qDebug() << "Первый поток закончил свое дело";
    });

    connect(watcher2, &QFutureWatcher<void>::finished, this, [](){
        qDebug() << "Второй поток закончил свое дело";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete watcher1;
    delete watcher2;
}

//Метод запускает два потока
void MainWindow::StartRace(void){


    if(ui->rb_qtConcur->isChecked()){

        //ui->te_debug->append("Выполни ДЗ!");
        //Тут должен быть код ДЗ

        //QList<ExampleRace*> example_race_list = {concurRace1, concurRace2};
        //std::function<void(ExampleRace&, uint32_t*, bool, int)> make_race = &ExampleRace::DoWork;
        //QFuture<void> future1 = QtConcurrent::map(example_race_list, make_race);
        //watcher1->setFuture(future1);
        QFuture<void> future1 = QtConcurrent::run(&ExampleRace::DoWork, concurRace1, &number, true, ui->sb_initNum->value());
        QFuture<void> future2 = QtConcurrent::run(&ExampleRace::DoWork, concurRace2, &number, true, ui->sb_initNum->value());

        watcher1->setFuture(future1);
        watcher2->setFuture(future2);


    }
    else{
        emit race1->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
        emit race2->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
    }
}

//Обработка кнопки "Старт"
void MainWindow::on_pb_start_clicked()
{
    ui->pb_start->setEnabled(false);
    countFinish = 0;
    number = 0;
    StartRace( );
}
