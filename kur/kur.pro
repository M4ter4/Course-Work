QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brickwall.cpp \
    bullet.cpp \
    enemy.cpp \
    gameoverwidget.cpp \
    gamewidget.cpp \
    levelscene.cpp \
    main.cpp \
    mainwidget.cpp \
    player.cpp \
    powerup.cpp \
    square.cpp \
    startwidget.cpp \
    steelwall.cpp \
    tank.cpp

HEADERS += \
    brickwall.h \
    bullet.h \
    enemy.h \
    gameoverwidget.h \
    gamewidget.h \
    levelscene.h \
    mainwidget.h \
    player.h \
    powerup.h \
    square.h \
    startwidget.h \
    steelwall.h \
    tank.h

FORMS += \
    gameoverwidget.ui \
    gamewidget.ui \
    mainwidget.ui \
    startwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/brick.jpg \
    resources/enemy.jpg \
    resources/map1.txt \
    resources/player.jpg \
    resources/player.png \
    resources/steel.jpg
