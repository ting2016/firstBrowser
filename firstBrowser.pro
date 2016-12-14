QT      +=  webkitwidgets network widgets
HEADERS += \
    page.h \
    tab.h \
    browser.h

SOURCES += \
    tab.cpp \
    page.cpp \
    main.cpp \
    browser.cpp

# install
target.path = ./bin/
INSTALLS += target
