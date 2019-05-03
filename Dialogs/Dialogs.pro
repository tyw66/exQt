include(FindDialog/FindDialog.pri)
include(GotoDialog/GotoDialog.pri)
include(SortDialog/SortDialog.pri)

INCLUDEPATH+=FindDialog\
GotoDialog\
SortDialog

SOURCES += \
    main.cpp \
    mainboard.cpp

FORMS += \
    mainboard.ui

HEADERS += \
    mainboard.h

