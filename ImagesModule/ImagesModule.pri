INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/ImagesModule.h \
    $$PWD/src/QSharkImageProvider.h \
    $$PWD/src/QSharkImagesBackend.h
SOURCES += \
    $$PWD/ImagesModule.cpp \
    $$PWD/src/QSharkImageProvider.cpp \
    $$PWD/src/QSharkImagesBackend.cpp

RESOURCES += \
    $$PWD/qml/ImagesModule.qrc

OTHER_FILES += \
    $$PWD/qml/Images.qml
