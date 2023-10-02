#include "datamanager.h"
#include<QNetworkReply>
DataManager::DataManager(QGuiApplication*app,const QString&url):QObject(nullptr)
{
    this->app=app;
    this->manager =new QNetworkAccessManager(app);
    auto status=QObject::connect(manager, &QNetworkAccessManager::finished,this,&DataManager::onNetworkAccessManagerFinished);
    qDebug()<<status;
    request.setUrl(QUrl("https://zenquotes.io/api/random"));
    this->manager->get(request);
}

void DataManager::refresh()
{
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
    int space{};
    index=0;
    while(index!=std::string::npos)
    {
        index=newStr.find(" ",index+1);
        ++space;
        qDebug()<<index;
        if(space==10)
        {
           newStr.insert(index+1,"\n");
            space=0;
        }

    }
    setString(QString::fromStdString(newStr));
    qDebug()<<String;
    qDebug()<<response;
}

void DataManager::onQuitClicked()
{
    this->app->quit();
    qDebug()<<"Quit Clicked!";
    emit QuitClicked();
}

void DataManager::onHomeClicked()
{
    qDebug()<<"home Clicked!";
    this->refresh();
    emit HomeClicked();
}

void DataManager::onAboutClicked()
{   qDebug()<<"about Clicked!";
    emit AboutClicked();
}

void DataManager::onProfileClicked()
{   qDebug()<<"profile Clicked!";
    emit ProfileClicked();
};

