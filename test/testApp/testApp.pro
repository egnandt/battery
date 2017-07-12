TEMPLATE = app

# Header files
HEADERS += $$_PRO_FILE_PWD_/selftest/inc/*.h

# Source files
SOURCES += $$_PRO_FILE_PWD_/src/*.cpp \
           $$_PRO_FILE_PWD_/selftest/src/*.cpp

# Include paths
INCLUDEPATH += $$_PRO_FILE_PWD_/../testutils/inc \
               $$_PRO_FILE_PWD_/inc \
			   $$_PRO_FILE_PWD_/selftest/inc

# Library linking
LIBS += -L$$INSTALL_DIR/testApp \
        -L$$(GMOCK_LIB_DIR) \
        -L$$(GTEST_LIB_DIR) \
        -ltestutils \
        -lgmock \
        -lgtest \
        -lgcov

# Compiler flags
include($$_PRO_FILE_PWD_/../../qmakeUtils/testapplicationcommon.pri)
