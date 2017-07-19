TEMPLATE = subdirs
CONFIG += ordered

# Adding subprojects
SUBDIRS = $$_PRO_FILE_PWD_/test \
          $$_PRO_FILE_PWD_/batteryApp

# Adding QML files and config to project tree
DISTFILES += $$_PRO_FILE_PWD_/config/config.ini \
             $$_PRO_FILE_PWD_/qml/*.qml \
             $$_PRO_FILE_PWD_/qml/Instruments/*.qml \
             $$_PRO_FILE_PWD_/qml/Plot/*.qml
