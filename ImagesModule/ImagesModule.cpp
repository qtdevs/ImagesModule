#include "ImagesModule.h"

#include "src/QSharkImageProvider.h"
#include "src/QSharkImagesBackend.h"

// class QtImagesModule

void QtImagesModule::initialize()
{
    qmlRegisterType<QSharkImagesBackend>("QtShark.Images.private", 1, 0, "ImagesBackend");
    qmlRegisterSingletonType(QUrl(QStringLiteral("qrc:/QtImagesModule/Images.qml")), "QtShark.Images", 1, 0, "QtImages");
}

void QtImagesModule::initEngine(QQmlEngine *engine)
{
    QSharkImageProvider::initEngine(engine);
}

// class QtImages

QString QtImages::load(const QString &id, const QImage &image)
{
    return QSharkImageProvider::set(id, image);
}

QString QtImages::loadFromFile(const QString &id, const QString &fileName)
{
    return QSharkImageProvider::loadFromFile(id, fileName);
}

QString QtImages::loadFromData(const QString &id, const QByteArray &image)
{
    return QSharkImageProvider::loadFromData(id, image);
}

void QtImages::release(const QString &id)
{
    QSharkImageProvider::set(id, QImage());
}
