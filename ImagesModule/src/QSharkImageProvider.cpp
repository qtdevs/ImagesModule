#include "QSharkImageProvider.h"

#include <QStringBuilder>

#if defined(QT_DEBUG)
Q_LOGGING_CATEGORY(qlcImageProvider, "QtShark.Images")
#else
Q_LOGGING_CATEGORY(qlcImageProvider, "QtShark.Images", QtWarningMsg)
#endif // QT_DEBUG

QReadWriteLock                                 QSharkImageProvider::imageGuard;
QHash<QString, QSharkImageProvider::ImageInfo> QSharkImageProvider::imageInfos;

QSharkImageProvider::QSharkImageProvider()
    : QQuickImageProvider(Image)
{
}

QSharkImageProvider::~QSharkImageProvider()
{
}

QImage QSharkImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QReadLocker locker(&imageGuard);

    QString key = id.left(id.lastIndexOf(QLatin1Char('/')));
    ImageInfo imageInfo = imageInfos.value(key);
    if (imageInfo.second.isNull()) {
        return QImage();
    }

    QSize sz = imageInfo.second.size();
    if (size != Q_NULLPTR) {
        *size = sz;
    }

    if (requestedSize.isValid()
            && (requestedSize != sz)) {
        return imageInfo.second.scaled(requestedSize);
    }

    return imageInfo.second;
}

void QSharkImageProvider::initEngine(QQmlEngine *engine)
{
    Q_CHECK_PTR(engine);

    if (engine && !engine->imageProvider(QStringLiteral("ericzh"))) {
        engine->addImageProvider(QStringLiteral("ericzh"), new QSharkImageProvider());
    }
}

QString QSharkImageProvider::set(const QString &id, const QImage &image)
{
    QWriteLocker locker(&imageGuard);

    if (id.startsWith(QLatin1Char('/'))) {
        qCWarning(qlcImageProvider) << "Unexpected prefix '/' in" << id;
        return QString();
    } else if (id.endsWith(QLatin1Char('/'))) {
        qCWarning(qlcImageProvider) << "Unexpected suffix '/' in" << id;
        return QString();
    }

    ImageInfo &imageInfo = imageInfos[id];
    if (image != imageInfo.second) {
        imageInfo.second = image;
        imageInfo.first += 1;
    }

    return QStringLiteral("image://ericzh/") % id
            % QStringLiteral("/") % QString::number(imageInfo.first);
}

QString QSharkImageProvider::loadFromFile(const QString &id, const QString &fileName)
{
    QImage tempImage;
    if (tempImage.load(fileName)) {
        return set(id, tempImage);
    }

    return QString();
}

QString QSharkImageProvider::loadFromData(const QString &id, const QByteArray &image)
{
    QImage tempImage;
    if (tempImage.loadFromData(image)) {
        return set(id, tempImage);
    }

    return QString();
}

QString QSharkImageProvider::url(const QString &id)
{
    QReadLocker locker(&imageGuard);

    ImageInfo imageInfo = imageInfos.value(id);
    if (imageInfo.second.isNull()) {
        return QString();
    }

    return QStringLiteral("image://ericzh/") % id
            % QStringLiteral("/") % QString::number(imageInfo.first);
}
