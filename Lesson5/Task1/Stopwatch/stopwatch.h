#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QTimer>
#include <QTime>
#include <QDebug>

class StopWatch : public QObject
{
    Q_OBJECT

public:
    StopWatch(QObject *parent = nullptr);

    void start_stop_timer();
signals:

    void set_timer_value(QTime timer_value);
    void set_round_info(int round_number, QTime round_time);
    void set_round_info(QString str);
    void set_btn_clear_enabled_flag(bool is_btn_clear_enabled);

public Q_SLOTS:



    //Слот обработки нажатия кнопки "Очистить"
    void btn_clear_release();
    void btn_round_release();
private Q_SLOTS:
    void get_timer_value_msec();

private:

    bool is_timer_started;
    QTimer* timer;
    QTime* result_timer_value;
    QTime* timer_value;


    //Флаги доступности для кнопок в основном виджете
    bool is_btn_clear_enabled;
    //bool is_btn_round_enabled;

    struct Round{

        Round(int round_number, QTime round_time);
        int round_number;
        QTime round_time;

    };

    QVector<Round> round_vector;



};

#endif // STOPWATCH_H
