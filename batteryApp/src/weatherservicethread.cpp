#include "weatherservicethread.h"

void WeatherServiceThread::run()
{

    sleep(10);
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    emit taskComplete();
}

void WeatherServiceThread::onResult(QNewtorkReply* reply)
{
    if (m_currentReply->error() != QNetworkReply::NoError)
        return;  // ...only in a blog post

    QString data = (QString) reply->readAll();

    QScriptEngine engine;
    QScriptValue result = engine.evaluate(data);
    QScriptValue entries = result.property("feed").property("entry");
    QScriptValueIterator it(entries);
    while (it.hasNext()) {
        it.next();
        QScriptValue entry = it.value();

        QString link = entry.property("content").property("src").toString();
        int viewCount = entry.property("yt$statistics").property("viewCount").toInteger();

        // Do something with those...
    }
}
