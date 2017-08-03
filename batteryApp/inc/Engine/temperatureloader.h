#ifndef TEMPERATURELOADER_H
#define TEMPERATURELOADER_H

#include "datapoint.h"
#include "abstracttemperatureloader.h"
#include <QObject>
#include <memory>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include "abstractmodel.h"
#include "basestate.h"

class TemperatureLoader: public AbstractTemperatureLoader, public BaseState
{
    Q_OBJECT
public: //From AbstractTemperatureLoader

    /**
     * @brief Constructor
     */
    TemperatureLoader(AbstractModel &aModel);

    void runState();
    /**
     * @brief startLoad
     * @return
     */
    void startLoad();

    /**
     * @brief Getter for the temperature values
     * @return
     */
    QList<float> getListOfTemperatureValues();

    /**
     * @brief getNetworkRequest
     * @param index
     * @return The request
     */
    QNetworkRequest getNetworkRequest(int index);

signals:
    void temperatureLoaded();

public slots:
    void responseReceived(QNetworkReply *reply);

private:
    QList<float> m_listOfTemperatureValues;
    QNetworkAccessManager m_networkManager;
    QNetworkReply *m_currentReply;
    QNetworkRequest m_request;
    QUrl m_url;
    QUrlQuery m_query;
    QList<QString> m_urlParameters;
    int m_index;
    AbstractModel &m_model;
};

#endif // TEMPERATURELOADER_H
