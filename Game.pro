# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application]
TARGET = Game

CONFIG += sailfishapp
CONFIG += object_parallel_to_source

INCLUDEPATH += src/includes \
            src/SmartSlog/expat \
            src/SmartSlog/scew \
            src/SmartSlog

SOURCES += src/Game.cpp       \
        $$system(ls src/SmartSlog/utils/*.c)\
        $$system(ls src/SmartSlog/expat/*.c)\
        $$system(ls src/SmartSlog/scew/*.c) \
        $$system(ls src/SmartSlog/ckpi/*.c) \
        $$system(ls src/SmartSlog/*.c)      \
        $$system(ls src/ontology/*.c) \
    src/sib.cpp

HEADERS += \
    src/sib.h

OTHER_FILES += qml/Game.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/Game.changes.in \
    vqml/irusgame.js \
    rpm/Game.spec \
    rpm/Game.yaml \
    translations/*.ts \
    Game.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 256x256

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/Game-de.ts

DISTFILES += \
    qml/pages/GameView.qml \
    virusgame.js \
    qml/GameArea.qml \
    qml/virusgame.js \
    qml/Particle.qml \
    qml/Controller.qml \
    qml/Entity.qml \
    qml/EntityManager.qml \
    qml/VirusesDemo.qml \
    qml/Particle.qml \
    qml/WinnerDialog.qml \
    qml/pages/ConnectPage.qml \
    qml/pages/Background1.jpg \
    qml/pages/ConnectMenu.qml

QMAKE_CFLAGS = -std=c99 -DMTENABLE -DHAVE_EXPAT_CONFIG_H -DHAVE_MEMMOVE

DEFINES += _GNU_SOURCE

RESOURCES += \
    resource.qrc
