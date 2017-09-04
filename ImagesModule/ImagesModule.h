#ifndef IMAGESMODULE_H
#define IMAGESMODULE_H

#include <QQmlEngine>

class QtImagesModule
{
public:
    static void initialize();
    static void initEngine(QQmlEngine *engine);
};

class QtImages
{
public:
    static QString load(const QString &id, const QImage &image);
    static QString loadFromFile(const QString &id, const QString &filename);
    static QString loadFromData(const QString &id, const QByteArray &image);
    static void release(const QString &id);
};

#endif // IMAGESMODULE_H
