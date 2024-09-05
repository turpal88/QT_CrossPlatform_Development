#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent) : QObject(parent)
{
timer = new QTimer(parent);
timer->setInterval(100);
timer_value = new QTime(0,0);



btn_watchdog_timer = new QTimer(parent);
btn_watchdog_timer->setInterval(20);
round_timer_value = new QTime(0,0);

is_btn_clear_enabled = false;
is_btn_round_enabled = false;

round_vector.clear();
//round.round_number = 0;
//round.round_time.setHMS(0,0,0);
connect(timer, &QTimer::timeout, this, &StopWatch::get_timer_value_msec);
connect(btn_watchdog_timer, &QTimer::timeout, this, &StopWatch::btn_watchdog);

btn_watchdog_timer->start();
}

StopWatch::Round::Round(int round_number, QTime round_time){

    this->round_number = round_number;
    this->round_time = round_time;
}


void StopWatch::toggle_start_stop_btn(){
if(start_stop_btn_title == "Старт"){
    start_stop_btn_title = "Стоп";
    timer->start();


}  else if(start_stop_btn_title == "Стоп"){

    start_stop_btn_title = "Старт";
    timer->stop();
    round_vector.push_back(Round(round_vector.size() + 1, *round_timer_value));
    round_timer_value->setHMS(0,0,0);
    //qDebug() << QString::number(round_vector.at(round_vector.size() - 1).round_number) << " " << (round_vector.at(round_vector.size() - 1).round_time).toString("H:mm:ss.zzz");

}


emit start_stop_btn_title_toggled(start_stop_btn_title);

}

void StopWatch::init_start_stop_btn_title(QString start_stop_btn_title){

    this->start_stop_btn_title = start_stop_btn_title;
}

void StopWatch::get_timer_value_msec(){
 if(timer_value->msec() >= 100) emit set_timer_value(*timer_value);
    //if(timer_value->msec() > 1000.) *timer_value = timer_value->addSecs(1);


    *timer_value = timer_value->addMSecs(100);
    *round_timer_value = round_timer_value->addMSecs(100);

}

void StopWatch::btn_clear_release(){

    timer_value->setHMS(0,0,0);
    round_timer_value->setHMS(0,0,0);
    round_vector.clear();
    emit set_timer_value(*timer_value);
}

void StopWatch::btn_round_release(){
emit set_round_info(round_vector.at(round_vector.size() - 1).round_number, round_vector.at(round_vector.size() - 1).round_time);

}


void StopWatch::btn_watchdog(){

if(start_stop_btn_title == "Старт" && !(timer_value->toString("H:mm:ss.zzz") == "0:00:00.000")) is_btn_clear_enabled = true; else is_btn_clear_enabled = false;
if(round_vector.size() > 0) is_btn_round_enabled = true; else is_btn_round_enabled = false;
emit set_btn_clear_round_enabled_flag(is_btn_clear_enabled, is_btn_round_enabled);

}





