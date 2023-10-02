#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<memory>
#include"datamanager.h"
#include<QQmlContext>

int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    DataManager manager(&app,"https://zenquotes.io/api/random");

    QQmlContext*context;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    context=engine.rootContext();
    context->setContextProperty("manager",&manager);

    engine.load(url);

    return app.exec();
}
