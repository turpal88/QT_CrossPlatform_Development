#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent) : QObject(parent)
{
    timer = new QTimer(parent);
    timer->setInterval(100);
    timer_value = new QTime(0,0);
    result_timer_value = new QTime(0,0);
    is_timer_started = false;




    is_btn_clear_enabled = false;


    round_vector.clear();

    connect(timer, &QTimer::timeout, this, &StopWatch::get_timer_value_msec);

}

StopWatch::Round::Round(int round_number, QTime round_time){

    this->round_number = round_number;
    this->round_time = round_time;
}



void StopWatch::start_stop_timer(){

    if(!this->is_timer_started){
        this->is_timer_started = true;
        timer->start();
        is_btn_clear_enabled = false;

    }
    else{
        this->is_timer_started = false;
        timer->stop();
        is_btn_clear_enabled = true;
        round_vector.push_back(Round(round_vector.size() + 1, *timer_value));


        emit set_btn_clear_enabled_flag(is_btn_clear_enabled);
    }



}



void StopWatch::get_timer_value_msec(){
    if(timer_value->msec() > 100){
    emit set_timer_value(*timer_value);
    }



    *timer_value = timer_value->addMSecs(100);


}

void StopWatch::btn_clear_release(){

    timer_value->setHMS(0,0,0);

    round_vector.clear();
    is_btn_clear_enabled = false;
    emit set_btn_clear_enabled_flag(is_btn_clear_enabled);
    emit set_timer_value(*timer_value);
    emit set_round_info("Нет ни одного круга");
}

void StopWatch::btn_round_release(){
    if(round_vector.size() == 0){
        emit set_round_info("Нет ни одного круга");
    }
    else if(round_vector.size() == 1){
        emit set_round_info(round_vector.at(round_vector.size() - 1).round_number,
                            round_vector.at(round_vector.size() - 1).round_time);
        //qDebug() << result_timer_value->toString("H:mm:ss.zzz");
    }
    else{
        result_timer_value->setHMS(0,0,0,0);

        *result_timer_value = result_timer_value->addMSecs(round_vector.at(round_vector.size() - 1).round_time.msecsSinceStartOfDay() -
                round_vector.at(round_vector.size() - 2).round_time.msecsSinceStartOfDay());
        //qDebug() << result_timer_value->toString("H:mm:ss.zzz");
        emit set_round_info(round_vector.at(round_vector.size() - 1).round_number, *result_timer_value);
    }


}





