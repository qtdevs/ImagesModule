#ifndef QSHARKIMAGEPROVIDER_H
#define QSHARKIMAGEPROVIDER_H

#include <QReadWriteLock>
#include <QLoggingCategory>
#include <QQuickImageProvider>

Q_DECLARE_LOGGING_CATEGORY(qlcImageProvider)

class QSharkImageProvider : public QQuickImageProvider
{
private:
    QSharkImageProvider();
public:
    virtual ~QSharkImageProvider();

public:
    QImage requestImage(const QString &id, QSize *size,
                        const QSize &requestedSize) Q_DECL_FINAL;

public:
    static void initEngine(QQmlEngine *engine);
    static QString set(const QString &id, const QImage &image);
    static QString loadFromFile(const QString &id, const QString &fileName);
    static QString loadFromData(const QString &id, const QByteArray &image);
    static QString url(const QString &id);

private:
    static QReadWriteLock            imageGuard;
    typedef QPair<int, QImage>       ImageInfo;
    static QHash<QString, ImageInfo> imageInfos;
};

#endif // QSHARKIMAGEPROVIDER_H
