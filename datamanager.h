#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include<QNetworkAccessManager>
#include<QVector>
#include<QString>
#include <QGuiApplication>

class DataManager:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString String READ getString WRITE setString NOTIFY StringChanged FINAL)
private:
    QString String{"Excellence is not a skill."};
private:
    QNetworkAccessManager*manager{};
    QNetworkRequest request{};
public:
    explicit DataManager(QGuiApplication*app,const QString&url);
    DataManager()=delete;
    DataManager(const DataManager&)=delete;
    DataManager&operator=(DataManager&)=delete;
    QString getString()const{return this->String;};
    void setString(const QString&str)
    {
        if(String!=str)
        {
               this->String=str;
            emit StringChanged();
        }

    };
signals:
    void StringChanged();
private slots:
    void onNetworkAccessManagerFinished(QNetworkReply*reply);
};

#endif // DATAMANAGER_H
