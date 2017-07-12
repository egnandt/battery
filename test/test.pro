TEMPLATE = subdirs
CONFIG += ordered

# Adding subprojects
SUBDIRS = $$_PRO_FILE_PWD_/testUtils \
          $$_PRO_FILE_PWD_/testApp

# Define dependencies
testApp.depends += testutils
