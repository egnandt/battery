TEMPLATE = app

# QML files compiled to resource binary
RESOURCES = $$_PRO_FILE_PWD_/../*.qrc

# Header files
HEADERS += $$_PRO_FILE_PWD_/inc/*.h \
           $$_PRO_FILE_PWD_/inc/viewModels/*.h

# Source files
SOURCES += $$_PRO_FILE_PWD_/src/*.cpp \
           $$_PRO_FILE_PWD_/src/viewModels/*.cpp

# Include paths
INCLUDEPATH += $$_PRO_FILE_PWD_/inc \
               $$_PRO_FILE_PWD_/inc/viewModels

# Compiler flags
include($$_PRO_FILE_PWD_/../qmakeUtils/applicationcommon.pri)

# Define target for copying configuration file
copydata.commands = $(COPY_DIR) $$shell_path($$PWD/../config/config.ini) $$shell_path($$DESTDIR)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
