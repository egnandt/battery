#include "csvloader.h"
#include <QList>
#include <QTextStream>
#include <QDebug>

CSVLoader::CSVLoader(AbstractModel &aModel)
    :  m_model{aModel}
{

}

void CSVLoader::runState()
{
    startLoad();
    m_stateCallback->stateFinished(); //here or after start load?
}

void CSVLoader::startLoad()
{
    QStringList wordList;
    QList<DataPoint> dataPointList;
    QFile mFile(m_path);
    DataPoint dataPoint;
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "The file can't be open!";
        return;
    }

    QTextStream in(&mFile);

    while(!in.atEnd())
    {
        QString mText  = in.readLine();
        wordList = mText.split(',');
        dataPoint.m_coordinates.setX(wordList.at(0).toFloat());
        dataPoint.m_coordinates.setY(wordList.at(1).toFloat());
        dataPoint.m_elevation = wordList.at(2).toFloat();
        dataPoint.m_temperature = wordList.at(3).toFloat();
        dataPointList.append(dataPoint);
    }
    m_model.setDataPointList(dataPointList);
}

void CSVLoader::setPath(const QString &path)
{
    m_path = path;
}

