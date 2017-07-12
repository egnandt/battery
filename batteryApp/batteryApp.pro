TEMPLATE = app

# QML files compiled to resource binary
RESOURCES = $$_PRO_FILE_PWD_/../*.qrc

# Header files
HEADERS += $$_PRO_FILE_PWD_/inc/*.h

# Source files
SOURCES += $$_PRO_FILE_PWD_/src/*.cpp

# Include paths
INCLUDEPATH += $$_PRO_FILE_PWD_/inc \

# Compiler flags
include($$_PRO_FILE_PWD_/../qmakeUtils/applicationcommon.pri)

# Define target for copying configuration file
copydata.commands = $(COPY_DIR) $$shell_path($$PWD/../config/config.ini) $$shell_path($$DESTDIR)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
