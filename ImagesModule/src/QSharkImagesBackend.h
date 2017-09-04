#ifndef QSHARKIMAGESBACKEND_H
#define QSHARKIMAGESBACKEND_H

#include <QObject>

class QSharkImagesBackend : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString load(const QString &id, const QString &fileName);
    Q_INVOKABLE void release(const QString &id);
};

#endif // QSHARKIMAGESBACKEND_H
