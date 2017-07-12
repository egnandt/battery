# Adding Qt libraries
QT += core gui qml quick charts

# Defining compile flags
CONFIG += c++14
QMAKE_CXXFLAGS += -Wpedantic \
                  -pedantic-errors \
                  -Werror \
                  -Wsign-compare

# Set output directory
Release:DESTDIR = $$INSTALL_DIR/batteryApp
Release:OBJECTS_DIR = $$INSTALL_DIR/batteryApp/obj
Release:MOC_DIR = $$INSTALL_DIR/batteryApp/moc
Release:RCC_DIR = $$INSTALL_DIR/batteryApp/res
Release:UI_DIR = $$INSTALL_DIR/batteryApp/ui
Debug:DESTDIR = $$INSTALL_DIR/batteryApp
Debug:OBJECTS_DIR = $$INSTALL_DIR/batteryApp/obj
Debug:MOC_DIR = $$INSTALL_DIR/batteryApp/moc
Debug:RCC_DIR = $$INSTALL_DIR/batteryApp/res
Debug:UI_DIR = $$INSTALL_DIR/batteryApp/ui
