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

 Q_SIGNALS:
    void start_stop_btn_title_toggled(QString str);
    void set_timer_value(QTime timer_value);
    void set_round_info(int round_number, QTime round_time);
    void set_btn_clear_round_enabled_flag(bool is_btn_clear_enabled, bool is_btn_round_enabled);

public Q_SLOTS:
    //Слот для задания начального значения названия кнопки Старт/Стоп
    void init_start_stop_btn_title(QString start_stop_btn_title);

    //Слот для изменения названия кнопки Старт/Стоп при нажатии на кнопку
    void toggle_start_stop_btn();
    //Слот обработки нажатия кнопки "Очистить"
    void btn_clear_release();
    void btn_round_release();
private Q_SLOTS:
    void get_timer_value_msec();
    void btn_watchdog();
private:
    QString start_stop_btn_title;
    QTimer* timer;
    QTimer* btn_watchdog_timer;
    QTime* timer_value;
    QTime* round_timer_value;

    //Флаги доступности для кнопок в основном виджете
    bool is_btn_clear_enabled;
    bool is_btn_round_enabled;
    struct Round{

        Round(int round_number, QTime round_time);
        int round_number;
        QTime round_time;

    };

    QVector<Round> round_vector;



};

#endif // STOPWATCH_H
