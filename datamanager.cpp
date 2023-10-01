#include "datamanager.h"
#include<QNetworkReply>
DataManager::DataManager(QGuiApplication*app,const QString&url):QObject(nullptr)
{
    this->manager =new QNetworkAccessManager(app);
    auto status=QObject::connect(manager, &QNetworkAccessManager::finished,this,&DataManager::onNetworkAccessManagerFinished);
    qDebug()<<status;
    request.setUrl(QUrl("https://zenquotes.io/api/random"));
    this->manager->get(request);
}

void DataManager::onNetworkAccessManagerFinished(QNetworkReply*reply)
{
    if(reply->error())
    {
        qDebug()<<reply->errorString();
        return;
    };
    QString response=reply->readAll();
    auto newStr=response.toStdString();
    auto index= newStr.find(";");
    auto lastIndex=newStr.find("&",index);
    newStr= newStr.substr(index+1,--lastIndex-index);
    setString(QString::fromStdString(newStr));
    qDebug()<<String;
    qDebug()<<response;
};

