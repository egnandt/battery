#include "Engine/temperatureloader.h"
#include <QtScript>

TemperatureLoader::TemperatureLoader(AbstractModel &aModel) :
    m_url{"http://api.openweathermap.org/data/2.5/weather?"}, m_index{0}, m_model{aModel}
{
    QObject::connect(&m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(responseReceived(QNetworkReply*)));
}

void TemperatureLoader::runState()
{
    startLoad();
}

void TemperatureLoader::startLoad()
{
    m_index = 0;
    if(m_model.getDataPointList().length() > m_index) //good condition?
    {
        m_request = getNetworkRequest(m_index);
        m_currentReply = m_networkManager.get(m_request);  // GET
        qDebug()<<"Http request sent";
    }
    else
    {
        m_stateCallback->stateFinished();
    }
}

void TemperatureLoader::responseReceived(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug()<<"Error with HTTP request";
        //If there is any error with the web api call, fallback on hard-coded values from CSV
        //must have hardcoded values for temperature i
        if(m_model.getDataPointList().at(m_index).m_temperature != -10000)
        {
            //Http request error
            //m_stateCallback->errorOccured(Errors::NoWebServiceTemperatureValuesError);
            m_model.setTemperatureValue(m_model.getDataPointList().at(m_index).m_temperature);
        }
        else
        {
            m_stateCallback->errorOccured(Errors::NoTemperatureValuesError);
        }
    }
    else
    {
        QString data = (QString) reply->readAll(); //Parse JSON to a QString

        QScriptEngine engine;
        QScriptValue result = engine.evaluate(data);
        m_model.setTemperatureValue(((float)result.property("main").property("temp").toNumber())-272.15); //taking the needed fields, convert to celsius
    }
    qDebug()<<"JSON received ";

    /* Could have also used QJsonDocument
    though QScriptEngine is backwards-compatible
    with Qt4
    */



    /*
    Weather Service API response in JSON looks like this:
    {"coord":{"lon":139,"lat":35},
    "sys":{"country":"JP","sunrise":1369769524,"sunset":1369821049},
    "weather":[{"id":804,"main":"clouds","description":"overcast clouds","icon":"04n"}],
    "main":{"temp":289.5,"humidity":89,"pressure":1013,"temp_min":287.04,"temp_max":292.04},
    "wind":{"speed":7.31,"deg":187.002},
    "rain":{"3h":0},tg
    "dt":1369824698,
    "id":1851632,
    "name":"Shuzenji",
    "cod":200}
    */


    ++m_index;
    if(m_model.getDataPointList().length() > m_index) //good condition?
    {
        m_currentReply = m_networkManager.get(getNetworkRequest(m_index));  // GET
        qDebug()<<"Http request sent";
    }
    else
    {
        m_stateCallback->stateFinished();
    }
}

QNetworkRequest TemperatureLoader::getNetworkRequest(int index)
{
    m_urlParameters.append(QString::number(m_model.getDataPointList().at(index).m_coordinates.x()));
    m_urlParameters.append(QString::number(m_model.getDataPointList().at(index).m_coordinates.y()));
    m_urlParameters.append("7034c87abb269138fc2ff6e9ff6fc6e5"); //required by Web Service
    m_query.addQueryItem("lat", m_urlParameters.at(0));
    m_query.addQueryItem("lon", m_urlParameters.at(1));
    m_query.addQueryItem("appid", m_urlParameters.at(2));
    m_url.setQuery(m_query);
    m_request.setUrl(m_url);
    m_urlParameters.clear(); //clear the url parameters
    m_query.clear(); //clear the query

    return m_request;
}
