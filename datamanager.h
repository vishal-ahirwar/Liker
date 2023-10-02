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
    QGuiApplication*app;
private:
    QNetworkAccessManager*manager{};
    QNetworkRequest request{};
public:

    explicit DataManager(QGuiApplication*app,const QString&url);
    ~DataManager();;
    DataManager()=delete;
    DataManager(const DataManager&)=delete;
    DataManager&operator=(DataManager&)=delete;
    QString getString()const;;
    void setString(const QString&str);
private:
    void refresh();
private:
signals:
    void StringChanged();
    void QuitClicked();
    void HomeClicked();
    void AboutClicked();
    void ProfileClicked();
public slots:
    void onNetworkAccessManagerFinished(QNetworkReply*reply);
    void onQuitClicked();
    void onHomeClicked();
    void onAboutClicked();
    void onProfileClicked();
};

inline DataManager::~DataManager()
{
    delete manager;
}

inline QString DataManager::getString() const{return this->String;}

inline void DataManager::setString(const QString &str)
{
    if(String!=str)
    {
        this->String=str;
        emit StringChanged();
    }

}

#endif // DATAMANAGER_H
