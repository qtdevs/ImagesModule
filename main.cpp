#include <QtGui>
#include <QtQml>

#include "ImagesModule.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtImagesModule::initialize();
    QQmlApplicationEngine engine;
    QtImagesModule::initEngine(&engine);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
