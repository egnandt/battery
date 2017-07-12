# Adding Qt libraries
QT += core gui qml quick charts

# Defining compile flags
CONFIG += c++14 gcov
QMAKE_CXXFLAGS += -O0 \
                  -isystem $$(GMOCK_INCLUDE_DIR) \
                  -isystem $$(GTEST_INCLUDE_DIR)

# Set output directory
Release:DESTDIR = $$INSTALL_DIR/testApp
Release:OBJECTS_DIR = $$INSTALL_DIR/testApp/obj
Release:MOC_DIR = $$INSTALL_DIR/testApp/moc
Release:RCC_DIR = $$INSTALL_DIR/testApp/res
Release:UI_DIR = $$INSTALL_DIR/testApp/ui
Debug:DESTDIR = $$INSTALL_DIR/testApp
Debug:OBJECTS_DIR = $$INSTALL_DIR/testApp/obj
Debug:MOC_DIR = $$INSTALL_DIR/testApp/moc
Debug:RCC_DIR = $$INSTALL_DIR/testApp/res
Debug:UI_DIR = $$INSTALL_DIR/testApp/ui
