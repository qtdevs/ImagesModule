#include "QSharkImagesBackend.h"
#include "QSharkImageProvider.h"

QString QSharkImagesBackend::load(const QString &id, const QString &filename)
{
    return QSharkImageProvider::loadFromFile(id, filename);
}

void QSharkImagesBackend::release(const QString &id)
{
    QSharkImageProvider::set(id, QImage());
}
