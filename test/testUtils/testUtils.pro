TEMPLATE = lib
CONFIG += staticlib

# Header files
HEADERS += $$_PRO_FILE_PWD_/inc/*.h

# Source files
SOURCES += $$_PRO_FILE_PWD_/src/*.cpp

# Include paths
INCLUDEPATH += $$_PRO_FILE_PWD_/inc

# Library linking
LIBS += -L$$(GMOCK_LIB_DIR) \
        -L$$(GTEST_LIB_DIR) \
        -lgmock \
        -lgtest

# Compiler flags
include($$_PRO_FILE_PWD_/../../qmakeUtils/testapplicationcommon.pri)
