#ifndef WEATHERSERVICETHREAD_H
#define WEATHERSERVICETHREAD_H

#include <QThread>
#include <QNetworkAccessManager>

class WeatherServiceThread: public QThread
{
    Q_OBJECT
    void run();
    void onResult(QNetworkReply*);

signals:
    void taskComplete();

private:
    QNetworkAccessManager networkManager;
};

#endif // WEATHERSERVICETHREAD_H
