#include <QCoreApplication>
#include <QtNetwork>
#include <QtSql>
#include <QDebug>
#include <QtPlugin>

//Q_IMPORT_PLUGIN(qsqlpsql)


int main(int argc, char** argv){

    QCoreApplication a(argc, argv);
    QTcpSocket tcp_socket(QObject *parent = nullptr);
    QTcpServer tcp_server(QObject *parent = nullptr);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("qt_db");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("Cnjkbwf1988!");
    db.open();
    if(db.isOpen()){
        QSqlQuery query;
        QString str = "CREATE TABLE addressbook (number INTEGER PRIMARY KEY NOT NULL, "
                      "name VARCHAR (15), phone VARCHAR(12), "
                      "email VARCHAR(15);";
        if (!query.exec(str)) {
            qDebug() << "Unable to create a table";
        }

    }else{
        qDebug() << db.lastError();

        qDebug() << "Could not to connect to database";
    }


    return a.exec();
}
